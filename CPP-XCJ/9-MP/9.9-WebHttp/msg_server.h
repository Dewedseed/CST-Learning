#include <map>
#include <queue>
#include <string>
#include <functional>
#include <thread>
#include <mutex>

struct Msg{
    std::string key;
    std::string data;
};

class MsgServer
{
public:
    using MsgCall = std::function<void(const Msg&)>;

    /// @para key message keyword for find function
    /// @para call function callback
    void Reg(std::string key, MsgCall call);

    /// @para msg message
    void Send(const Msg& msg);

    /// Thread function
    void Start();
    void Wait();
    void stop();

private:
    /// main cycle
    void Run();

    /// @para msg distribute message
    void Distribute(const Msg& msg);

    // call function base key
    std::map<std::string, MsgCall> calls_;
    // massage queue
    std::queue<Msg> msgs_;
    // thread
    std::thread th_;
    // exit thread
    bool is_exit_{ false };
    // mutex
    std::mutex mux_;
};
