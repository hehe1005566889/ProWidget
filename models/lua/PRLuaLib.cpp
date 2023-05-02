#include "PRLuaLib.hpp"
#include "ui/MainWindow.h"
#include "models/prml/PRReader.h"

namespace prlua
{

int PWEvent::bindCallBack(lua_State *l)
{
    int c = lua_gettop(l);
    if(c != 2)
    {
        Error("bindCallBack -> Need 2 String Argument");
        return -1;
    }

    auto name = luaL_checkstring(l, 1);
    auto callback = luaL_checkstring(l, 2);

    PRDoc* doc;
    MainWindow::Instance->FetchDoc(doc);
    if(doc == nullptr)
    {
        Error("doc not init");
        return -1;
    }

    PRElement* element;
    if(!doc->FetchItem(name, element))
    {
        Error("item not init");
        return -1;
    }
    element->BindCallBack(callback);
    Debug("[Script] Bind Success");

    return 1;
}

}
