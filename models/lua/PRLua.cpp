#include "PRLua.h"

#include "models/basic/Exceptions.hpp"

extern "C" {
#include "models/lua/lib/lauxlib.h"
#include "models/lua/lib/lualib.h"
}

namespace prlua
{

PRLuaMain::PRLuaMain()
{

}

PRLuaMain::~PRLuaMain()
{
    KillLibs();
}

void PRLuaMain::LoadLibs()
{
    _state = (luaL_newstate());
    luaL_openlibs(_state);
}

void PRLuaMain::KillLibs()
{
    lua_close(_state);
}

void PRLuaMain::PushAndCall(const QString &luaCode)
{
    int result = luaL_loadstring(_state, luaCode.toStdString().c_str());
    if(result)
        THROW(PRLUAEXCP());

    result = lua_pcall(_state, 0, 0, 0);
    if(result)
        THROW(PRLUAEXCP());
}

void PRLuaMain::RegisterFunction(const QString &name, lua_CFunction func)
{
    lua_register(_state, name.toStdString().c_str(), func);
}

}
