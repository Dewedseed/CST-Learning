#pragma once

#include <string>
class XTask {
public:
    struct Data {
        std::string type; // task type
        std::string src; // source video file
        std::string des; // destination file

        std::string password;

        bool is_enc{ true }; // encryption / decryption

        int start_sec{ 0 }; // cut begin time
        int end_sec{ 0 }; // cut end time
    };

    /// start process task
    /// @para Data task configure parameter
    /// @return execute state
    virtual bool Start(const Data&) = 0;

    /// Get task progress
    /// @return 0 ~ 100
    virtual int Progress() = 0;

    /// video total time(s)
    virtual int TotalSec() = 0;

    /// if task is running
    virtual bool Running() = 0;

    /// clear buff
    virtual void Clear() = 0;
};
