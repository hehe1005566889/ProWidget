#ifndef PROWIDGETAPI_H
#define PROWIDGETAPI_H

namespace prlua {
class PRLuaMain;
}

class ProWidgetAPI
{
public:
    prlua::PRLuaMain* GetScriptEngine();

    void RegisterScriptAPI();
};

#endif // PROWIDGETAPI_H
