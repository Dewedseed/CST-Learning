#include "http_server.h"

#include <iostream>
using namespace std;

void HttpServer::Init() {
    Reg("post", [this](const Msg& msg) {
        Post(msg);
    });
    Reg("get", [this](const Msg& msg) {
        Get(msg);
    });
    Reg("head", [this](const Msg& msg) {
        Head(msg);
    });
}

void HttpServer::Post(const Msg& msg) {
    cout << __PRETTY_FUNCTION__ << msg.key << ":" << msg.data << endl;
}

void HttpServer::Get(const Msg& msg) {
    cout << __PRETTY_FUNCTION__ << msg.key << ":" << msg.data << endl;
}

void HttpServer::Head(const Msg& msg) {
    cout << __PRETTY_FUNCTION__ << msg.key << ":" << msg.data << endl;
}
