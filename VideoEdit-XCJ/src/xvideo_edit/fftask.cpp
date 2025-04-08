#include "fftask.h"
#include "x_exec.h"
#include "log_fac.h"

#include <exception>
#include <iostream>
#include <string>

using namespace std;

#define DEFAULTPASS "0123456789ABCDEF0123456789ABCDEF"

// 00:21:12 = (00 * 60 + 21) * 60 + 12
static int TimeToSecond(const string& s) {
    if (s.size() < 8) return 0;
    int h = 0;
    int m = 0;
    int sec = 0;
    try {
        h = stoi(s.substr(0, 2));
        m = stoi(s.substr(3, 2));
        sec = stoi(s.substr(6, 2));
    } catch (const std::exception&) {
        LOGERROR("Error parse time string: " + s);
    }
    return h * 3600 + m * 60 + sec;
}

bool FFTask::Start(const Data& para) {
    LOGINFO("Start ffmpeg task");

    // cmd ffmpeg -y -i test.mp4 out.mp4
    string cmd = "ffmpeg -y";
    if (para.type == "play") {
        cmd = "ffplay";
    }
    // decryption: ffmpeg -decryption_key password -i en.mp4 de.mp4
    if (!para.is_enc && !para.password.empty()) {
        string pass = DEFAULTPASS;
        for (int i = 0; i < para.password.size() && i < pass.size(); ++i) {
            pass[i] = para.password[i];
        }
        cmd += " -decryption_key " + pass;
    }
    // cmd ffmpeg -y -ss 10 -t 5 -i test.mp4 out.mp4
    if (para.start_sec > 0) {
        cmd += " -ss " + to_string(para.start_sec);
    }
    if (para.end_sec > 0) {
        int t = para.end_sec - para.start_sec;
        if (t > 0)
            cmd += " -t " + to_string(t);
    }
    cmd +=  " -i " + para.src;
    // encryption
    // cmd ffmpeg -y -i test.mp4 out.mp4 -encryption_key password en.mp4
    if (para.is_enc && !para.password.empty()) {
        string pass = DEFAULTPASS;
        for (int i = 0; i < para.password.size() && i < pass.size(); ++i) {
            pass[i] = para.password[i];
        }
        cmd += " -encryption_scheme cenc-aes-ctr -encryption_kid 0123456789ABCDEF0123456789ABCDEF ";
        cmd += " -encryption_key ";
        cmd += pass;
    }

    if (!para.des.empty())
        cmd += " " + para.des;

    LOGINFO("FFmpeg CMD: " + cmd);

    // execute
    exec_.Start(cmd.c_str(), [this](const string& s){
        LOGDEBUG(s);
        // output progress
        // Duration: 00:00:30.00, start: 0.000000, bitrate: 3727 kb/s
        {if (total_sec_ <= 0) {
            auto pos = s.find("Duration: ");
            if (pos != string::npos) {
                string tmp = s.substr(pos + 10, 8);
                total_sec_ = TimeToSecond(tmp);
                cout << "Total Time = " << TotalSec() << "(s)" << endl;
                return;
            }}
        }
        // frame=104 fps= 40 q=29.0 size=768KiB time=00:00:03.40 bitrate=1848.7kbits/s speed=1.31x
        {
            auto pos = s.find("time=");
            if (pos != string::npos) {
                if(s.substr(pos+5, 3) == "N/A") return;
                string tmp = s.substr(pos+5, 8);
                int p = TimeToSecond(tmp);
                if (total_sec_ > 0)
                    progress_ = p * 100 / total_sec_;
                return;
            }
        }
    });

    return true;
}
