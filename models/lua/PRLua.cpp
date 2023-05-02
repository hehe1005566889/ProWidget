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

void PRLuaMain::CallLuaFunction(const QString &name, std::initializer_list<QVariant> args)
{
    int ret = lua_getglobal(_state, name.toStdString().c_str());
    if(!ret)
    {
        Error("[Script] Function Can't Find");
        return;
    }

    for(const auto &item : args)
    {
        switch(item.type())
        {

        case QVariant::Bool:
            lua_pushboolean(_state, item.toBool() ? 0 : 1);
            break;
        case QVariant::Int:
            lua_pushinteger(_state, item.toInt());
            break;
        case QVariant::Double:
            lua_pushnumber(_state, item.toDouble());
            break;
        case QVariant::String:
            lua_pushstring(_state, item.toString().toStdString().c_str());
            break;
        default:
            lua_pushnil(_state);
            Warn("[Script] Current Argument Type Is Not Supported, System Will Push 'Nil' To Script");
            break;
        }
    }

    if (lua_pcall(_state, args.size(), 0, 0) != LUA_OK)
    {
        Error(lua_tostring(_state, -1));
        THROW(PRLUAEXCP());
    }
}

void PRLuaMain::PushAndCall(const QString &luaCode)
{
    int result = luaL_loadstring(_state, luaCode.toStdString().c_str());
    if(result)
        THROW(PRLUAEXCP());

    result = lua_pcall(_state, 0, 0, 0);
    if(result)
    {
        Error(lua_tostring(_state, -1));
        THROW(PRLUAEXCP());
    }
}

void PRLuaMain::RegisterFunction(const QString &name, lua_CFunction func)
{
    lua_register(_state, name.toStdString().c_str(), func);
}

}
