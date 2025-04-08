#include "xvideo_input.h"
#include "logger.h"
#include "user_input.h"
#include "xdir.h"
#include "xtask.h"
#include "xdir.h"
#include "log_fac.h"

#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

static string RepeatChar(char c, int times) {
    return string(times, c);
}

void XVideoInput::RunTask(XTask &task, const XTask::Data &data) {
    task.Start(data);
    // show progress
    int p = 0;
    int l = 0;
    int len = 40;
    while (task.Running()) {
        p = task.Progress();
        p = p * len / 100;
        if (p != l) {
            cout << "\r" << data.src << " ["
                 << RepeatChar('=', p)
                 << ">"
                 << RepeatChar(' ', len - p)
                 << "] " << data.des << flush;
            l = p;
        }
    }
    cout << "\r" << data.src << " ["
         << RepeatChar('=', len + 1)
         << "] " << data.des << flush;
}

void XVideoInput::Start(std::unique_ptr<XTask> task) {
    LOGINFO("VideoInput Start");

    UserInput user;
    XTask::Data data;

    LOGDEBUG("Register task function and input paramter function");
    user
        .RegTask("cv", [&]{
            LOGDEBUG("Register cv task");
            data.type = "cv";
            // batch task
            if (XDir::IsDir(data.src)) {
                LOGDEBUG("Batch task");
                XDir dir;
                std::vector<XFile> files = dir.GetFiles(data.src);
                for (auto f : files) {
                    XTask::Data d = data;
                    d.src = f.path;
                    if (!XDir::IsDir(data.des)) {
                        XDir::Create(data.des);
                    }
                    d.des = data.des + "/" + f.name;
                    task->Clear();
                    RunTask(*task, d);
                }
            } else {
                RunTask(*task, data);
            }
        })
        .RegTask("play", [&]{
            LOGDEBUG("Register play task");
            data.type = "play";
            task->Start(data);
        })
        .Reg("-s", [&](const string &s){
            LOGDEBUG("Register option: -s " + s);
            data.src = s;
        })
        .Reg("-d", [&](const string &s){
            LOGDEBUG("Register option: -d " + s);
            data.des = s;
        })
        .Reg("-b", [&](const string &s){
            LOGDEBUG("Register option: -b " + s);
            data.start_sec = stoi(s);
        })
        .Reg("-e", [&](const string &s){
            LOGDEBUG("Register option: -e " + s);
            data.end_sec = stoi(s);
        })
        .Reg("-p", [&](const string &s){
            LOGDEBUG("Register option: -p " + s);
            if (s.empty()) {
                cout << "password: " << flush;
                string pass;
                cin >> pass;
                data.password = pass;
            } else {
                data.password = s;
            }
        })
        .Reg("-dp", [&](const string &s){
            LOGDEBUG("Register option: -dp " + s);
            if (s.empty()) {
                cout << "password: " << flush;
                string pass;
                cin >> pass;
                data.password = pass;
            } else {
                data.password = s;
            }
            data.is_enc = false;
        });

    user.Start([&](vector<string> para){
        LOGINFO("Init video input task");

        data = XTask::Data();
        if (para.size() < 4) {
            // play test.mp4
            if (para.size() > 1)
                data.src = para[1];
            // cv test.mp4 out.mp4
            if (para.size() > 2)
                data.des = para[2];
        }
    });
}
