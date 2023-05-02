#include "Logger.h"

#include <QTime>
#include <iostream>

#ifdef PRWin
HANDLE Logger::consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

void Logger::LogInfo(const QString &msg)
{
    //Info Using HighLight White Color For Text Color
#ifdef PRWin
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#endif

    std::cout << "["
              << QTime::currentTime().toString().toStdString()
              << "] "
#ifdef PRUnix
              << "\033[36m[I] \033[0m"
#else
              << "[I] "
#endif
              << msg.toStdString()
              << std::endl;
}

void Logger::LogError(const QString &msg)
{
    //Error Using Red For Text Color
#ifdef PRWin
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED);
#endif
    std::cout << "["
              << QTime::currentTime().toString().toStdString().c_str()
              << "] "
#ifdef PRUnix
              << "\033[31m[E] \033[0m"
#elif
              << "[E] "
#endif
              << msg.toStdString().c_str()
              << std::endl;
}

void Logger::LogWarn(const QString &msg)
{
    //Warning Using Yellow For Font Color
#ifdef PRWin
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
#endif
    std::cout << "["
              << QTime::currentTime().toString().toStdString().c_str()
              << "] "
#ifdef PRUnix
              << "\033[38;5;220m[W] \033[0m"
#else
              << "[W] "
#endif
              << msg.toStdString().c_str()
              << std::endl;
}

void Logger::LogSuccess(const QString &msg)
{
    //Success Use Green For Font Color
#ifdef PRWin
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_GREEN);
#endif
    std::cout << "["
              << QTime::currentTime().toString().toStdString().c_str()
              << "] "
#ifdef PRUnix
              << "\033[32m[S] \033[0m"
#else
              << "[S] "
#endif
              << msg.toStdString().c_str()
              << std::endl;
}

void Logger::LogDebug(const QString &msg)
{
#ifndef ABBABB
    //Info Using HighLight White Color For Text Color
#ifdef PRWin
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
#endif

    std::cout << "["
              << QTime::currentTime().toString().toStdString()
              << "] "
#ifdef PRUnix
              << "\033[35m[D] \033[0m"
#else
              << "[D] "
#endif
              << msg.toStdString()
              << std::endl;
#endif
}
