#include "msg_server.h"
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

void MsgServer::Reg(std::string key, MsgCall call) {
    calls_[key] = call;
}

void MsgServer::Distribute(const Msg &msg) {
    auto ptr = calls_.find(msg.key);
    if (ptr == calls_.end()) {
        std::cerr << msg.key << "not register" << std::endl;
        return;
    }
    ptr->second(msg);
}

void MsgServer::Send(const Msg &msg) {
    msgs_.push(msg);
}

void MsgServer::Start() {
    th_ = std::thread(&MsgServer::Run, this);
}

void MsgServer::Wait() {
    if (th_.joinable()) th_.join();
}

void MsgServer::stop() {
    is_exit_ = true;
}

void MsgServer::Run() {
    while (!is_exit_) {
        if (msgs_.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            continue;
        }

        Msg msg;

        {
            std::lock_guard<std::mutex> lock(mux_);
            msg = msgs_.front();
            msgs_.pop();
        }

        Distribute(msg);
    }
}
