#ifndef LOGGER_H
#define LOGGER_H

#include "PlatForm.h"
#include <QString>

#ifdef PRWin
#include <windows.h>
#endif


#define Info(Message) Logger::LogInfo(Message);
#define Error(Message) Logger::LogError(Message);
#define Warn(Message) Logger::LogWarn(Message);
#define Success(Message) Logger::LogSuccess(Message);
#define Debug(Message) Logger::LogDebug(Message)

#define Assert(x, ...) \
if(!(x)){ \
        Error(__VA_ARGS__); \
}

class Logger
{
private:
#ifdef PRWin
    static HANDLE consolehwnd;
#endif

public:
    static void LogInfo(const QString& msg);
    static void LogError(const QString& msg);
    static void LogWarn(const QString& msg);
    static void LogSuccess(const QString& msg);
    static void LogDebug(const QString& msg);
};

typedef unsigned long long uint64;
typedef unsigned int uint32;
typedef unsigned char byte;

#endif // LOGGER_H
