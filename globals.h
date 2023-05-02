#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <memory.h>
#include <QObject>

#include "models/basic/Logger.h"
#include "models/basic/PlatForm.h"
#include "models/basic/Exceptions.hpp"

template<typename T>
using ref = std::shared_ptr<T>;

template<typename T>
using uni = std::unique_ptr<T>;


template <typename T, typename... Args>
constexpr ref<T> create_ref(Args &&...args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}
template <typename T, typename... Args>
constexpr uni<T> create_unique(Args &&...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

using i8 = char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned int;

#endif // GLOBALS_H
