#include "http_server.h"

#include <iostream>
#include <thread>

using namespace std;

int main()
{
    HttpServer server;
    server.Init();
    server.Start();

    server.Send({"post", "test post data"});
    server.Send({"get", "test get data"});
    server.Send({"head", "test head data"});

    this_thread::sleep_for(1s);
    server.stop();
    server.Wait();
}
