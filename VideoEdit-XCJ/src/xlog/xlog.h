#ifdef _WIN32
    #ifdef XLOG_EXPROTS
    #define XLOG_API __declspec(dllexport)
    #else
    #define XLOG_API __declspec(dllimport)
    #endif
#else
    #define XLOG_API
#endif

class XLOG_API Cxlog {
public:
private:
};

