#ifndef DUMB_LOGGER_HPP
#define DUMB_LOGGER_HPP

#pragma once
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>

namespace dumb
{

class Logger
{
  public:
    Logger()
    {
        printf("Logger initialized\n");
    };
    ~Logger() {};

    static char *getTimeString()
    {
        static char timeStr[20];
        time_t now = time(nullptr);
        struct tm *timeinfo = localtime(&now);
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);
        return timeStr;
    }

    void log(FILE *stream, const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vfprintf(stream, format, args);
        va_end(args);
    }

    void trace(const char *format, ...)
    {
        char *timeString = getTimeString();
        std::string formatString = std::string("[") + timeString + "] " + format;
        va_list args;
        va_start(args, format);
        log(stdout, formatString.data(), args);
        va_end(args);
    }
    void debug();
    void info();
    void warn();
    void error();

  private:
};

}; // namespace dumb

#endif // DUMB_LOGGER_HPP
