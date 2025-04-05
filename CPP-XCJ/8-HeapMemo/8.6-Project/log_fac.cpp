#include "log_fac.h"
#include "log_console_output.h"
#include "log_file_output.h"
#include "xlog_format.h"
#include "log_xml_format.h"
#include "xconfig.h"
#include "logger.h"

#include <memory>
#include <string>
#include <iostream>
using namespace std;

#define LOGFILE "log.txt"

/// @para con_file configure file
void LogFac::Init(const std::string& con_file){
    // get configure
    XConfig conf;
    bool re = conf.Read(con_file);

    string log_type   = "console";
    string log_file   = LOGFILE;
    string log_level  = "debug";
    string log_format = "";

    if (re) {
        log_type   = conf.Get("log_type");
        log_file   = conf.Get("log_file");
        log_level  = conf.Get("log_level");
        log_format = conf.Get("log_format");
    }

    // set log type (log file)
    if (log_type == "file") {
        if (log_file.empty()) {log_file = LOGFILE;}
        auto fout = make_unique<LogFileOutput>();
        if (!fout->Open(log_file)) {
            cerr << "Open file failed " << log_file << endl;
        }
        logger_.SetOutput(move(fout));
    } else {
        logger_.SetOutput(make_unique<LogConsoleOutput>());
    }

    // set log leve;
    if (log_level == "info") {
        logger_.SetLevel(LogLevel::INFO);
    } else if (log_level == "error") {
        logger_.SetLevel(LogLevel::ERROR);
    } else if (log_level == "fatal") {
        logger_.SetLevel(LogLevel::FATAL);
    } else {
        logger_.SetLevel(LogLevel::DEBUG);
    }

    // set log format
    if (log_format == "xml") {
        // logger_.SetFormat(new LogXMLFormat);
        logger_.SetFormat(make_unique<LogXMLFormat>());
    } else {
        logger_.SetFormat(make_unique<XLogFormat>());
    }
}
