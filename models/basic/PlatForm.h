#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(__linux__) || defined(__APPLE__)
#define PRUnix
#elif _WIN32
#define PRWin
#else
#error UnKnown Platform, ProWidget Not Support Yet~
#endif


#endif // PLATFORM_H
