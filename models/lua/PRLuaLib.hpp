#ifndef PRLUALIB_HPP
#define PRLUALIB_HPP

#include "globals.h"
#include "PRLua.h"

extern "C"
{
#include "lib/lua.h"
#include "models/lua/lib/lauxlib.h"
}

namespace prlua
{

static void(*onLuaPrint)(const QString& str) = nullptr;

class PWEvent
{
public:
    static int bindCallBack(lua_State* l);
    static int changeProp(lua_State* l);
};

static int printLog(lua_State* l)
{
    int c = lua_gettop(l);

    auto text = luaL_checkstring(l, 1);
    int type = c == 1 ? 0 : luaL_checknumber(l, 2);

    switch (type)
    {
    case 0: Info(text);       break;
    case 1: Warn(text);       break;
    case 2: Error(text);      break;
    case 3: Success(text);    break;
    }

    if(onLuaPrint != nullptr)
        onLuaPrint(text);

    return 0;
}

class PWBasic
{
public:
    static int msgbox(lua_State* l);

    static int loadPWLib(lua_State* l);
    static int createWidget(lua_State* l);
};

static int print(lua_State* l)
{
    int c = lua_gettop(l);
    QString r("[Script] ");

    for(int i = 1; i <= c; i++)
    {
        int t = lua_type(l, i);
        switch(t)
        {
        case LUA_TSTRING:
            r.append(luaL_checkstring(l, i));
            break;
        case LUA_TNUMBER:
            r.append(QString::number(luaL_checknumber(l, i)));
            break;
        case LUA_TBOOLEAN:
            r.append(QString());
            break;
        case LUA_TNIL:
            r.append("");
            break;
        case LUA_TFUNCTION:
            r.append("[NotSupport]");
            break; // TODO Support Function
        default:
            r.append("");
            break;
        }
    }

    if(onLuaPrint != nullptr)
        onLuaPrint(r);

    Info(r);
    return 0;
}

static void InitLuaLib(ref<PRLuaMain> _lua)
{
    _lua->RegisterFunction("printl", printLog);
    _lua->RegisterFunction("print", print);

    _lua->RegisterFunction("bindCallBack", PWEvent::bindCallBack);
    _lua->RegisterFunction("changeProp", PWEvent::changeProp);

    _lua->RegisterFunction("msgbox", PWBasic::msgbox);
    _lua->RegisterFunction("loadPWLib", PWBasic::loadPWLib);
    _lua->RegisterFunction("createWidget", PWBasic::createWidget);
}


}

#endif // PRLUALIB_HPP
