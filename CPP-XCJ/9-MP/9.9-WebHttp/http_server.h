#include "msg_server.h"

class HttpServer:public MsgServer
{
public:
    void Init();

private:
    void Post(const Msg& msg);
    void Get(const Msg& msg);
    void Head(const Msg& msg);
};
