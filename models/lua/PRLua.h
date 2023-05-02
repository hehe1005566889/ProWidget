#ifndef PRLUA_H
#define PRLUA_H

extern "C" {
#include "models/lua/lib/lua.h"
}

#include <QString>

namespace prlua
{

class PRLuaMain
{
public:
    PRLuaMain();
    ~PRLuaMain();

public:
    void LoadLibs();
    void KillLibs();

    void PushAndCall(const QString& luaCode);
    void RegisterFunction(const QString& name, lua_CFunction func);

private:
    lua_State* _state;
};

}

#endif // PRLUA_H
