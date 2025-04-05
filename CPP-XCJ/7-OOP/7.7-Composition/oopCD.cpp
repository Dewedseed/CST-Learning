#include <iostream>
using namespace std;

class LogOutput {
public:
    virtual ~LogOutput(){}
    virtual void output(const string& log) = 0;
};

class LogConsoleOutput:public LogOutput {
    void output(const string& log) override { cout << log << endl;}
};

class Logger {
public:
    Logger() {cout << "Create Logger\n";}
    virtual ~Logger() {
        delete output_;
        output_ = nullptr;

        cout << "Drop Logger\n";
    }

    void Write(const string& log) {
        output_->output(log);}
    void SetOutput(LogOutput* out) {
        output_ = out; }
private:
    LogOutput* output_{ nullptr };
};

class LogFac { // singleton
public:
    static LogFac& Instance() {
        static LogFac fac;
        return fac;
    }
    ~LogFac() {cout << "Drop LogFac\n";}

private:
    LogFac() {cout << "Create LogFac\n";}
    Logger logger_;
};

int main()
{
    Logger logger;
    logger.SetOutput(new LogConsoleOutput());
    logger.Write("test console log");

    // LogFac::Instance();
}
