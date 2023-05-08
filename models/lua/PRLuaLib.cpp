#include "PRLuaLib.hpp"

extern "C" {
#include "models/lua/lib/lstate.h"
}

#include "ui/MainWindow.h"
#include "models/prml/PRReader.h"

#include "platforms/PWMessageBox.h"

#include <QFile>

namespace prlua
{

int PWEvent::bindCallBack(lua_State *l)
{
    int c = lua_gettop(l);
    if(c != 2)
    {
        Error("[Script] bindCallBack -> Need 2 String Argument");
        return -1;
    }

    auto name = luaL_checkstring(l, 1);
    auto callback = luaL_checkstring(l, 2);

    PRDoc* doc;
    MainWindow::Instance->FetchDoc(doc);
    if(doc == nullptr)
    {
        Error("[Script] doc not init");
        return -1;
    }

    PRElement* element;
    if(!doc->FetchItem(name, element))
    {
        Error("[Script] item not init");
        return -1;
    }
    element->BindCallBack(callback);
    Debug("[Script] Bind Success");

    return 1;
}

int PWEvent::changeProp(lua_State *l)
{
    int c = lua_gettop(l);
    if(c != 3)
    {
        Error("[Script] changeProp -> Need 3 String Argument");
        return -1;
    }


    auto name  = luaL_checkstring(l, 1);
    auto key   = luaL_checkstring(l, 2);
    auto value = luaL_checkstring(l, 3);

    PRDoc* doc;
    MainWindow::Instance->FetchDoc(doc);
    if(doc == nullptr)
    {
        Error("[Script] doc not init");
        return -1;
    }

    PRElement* element;
    if(!doc->FetchItem(name, element))
    {
        Error("[Script] item not init");
        return -1;
    }

    element->SetAttribute(key, value);
    Debug("[Script] Call Set Done At Element : " + element->ElementNameDebug());

    return 1;
}

#define MSGBOX_INFO 0
#define MSGBOX_WARN 1
#define MSGBOX_ERROR 2

int PWBasic::msgbox(lua_State *l)
{
    int c = lua_gettop(l);
    if(c != 3)
    {
        Error("[Script] changeProp -> Need 3 String Argument");
        return -1;
    }


    auto title     = luaL_checkstring(l, 1);
    auto content   = luaL_checkstring(l, 2);
    auto type      = luaL_checkinteger(l, 3);

    switch(type)
    {
    case MSGBOX_INFO:
        PWMessageBox::Basic(title, content);
        break;
    case MSGBOX_ERROR:
        PWMessageBox::Critical(title, content);
        break;
    case MSGBOX_WARN:
        PWMessageBox::Warning(title, content);
        break;
    };

    return -1;
}

int PWBasic::loadPWLib(lua_State *l)
{
    auto path = SystemSetting->GetValue("Lua/LibraryPath").toString();

    auto code = QString("package.path = package.path .. \";[path]/?.lua\"").replace("[path]", path);

    int result = luaL_loadstring(l, code.toStdString().c_str());
    if(result)
    {
        Error("[Script] Lua Code Parsing Exception");
        THROW(PRLUAEXCP());
    }

    result = lua_pcall(l, 0, 0, 0);
    if(result)
    {
        Error(lua_tostring(l, -1));
        THROW(PRLUAEXCP());
    }

    return 1;
}

}
