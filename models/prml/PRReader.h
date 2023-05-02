#ifndef PRREADER_H
#define PRREADER_H

#include <QDomElement>
#include "globals.h"
#include "models/lua/PRLua.h"
#include <QWidget>

using namespace prlua;

namespace prml
{

#define FETCH_VALUE(node) node.attributes().contains("content") ? content = node.attribute("content") + "" : content = node.text() + ""

//#define FETCH_VALUE(node) node.attributes().contains("content") ? content = node.attribute("content") : content = node.text()
#define CHECK_ATTRI       if(!node.hasAttributes()) return;
#define FOREACH_ATTRIBUTE(node, ...) \
for(int i = 0; i <= node.attributes().count() - 1; i++) \
{ \
    auto item = node.attributes().item(i); \
    __VA_ARGS__ \
}

#define CHECK_POS(ITEM, VALUE) \
auto value = VALUE; \
if(!value.contains(",")) \
    THROW(PWDocEXCP()); \
auto xy = value.split(","); \
if(xy.count() != 2) \
    THROW(PWDocEXCP()); \
ITEM->move(xy[0].toInt(), xy[1].toInt()); \

#define CHECK_NAME(VALUE) \
parent->RegisterNamedItem(VALUE, this);

class PRDoc;

class PRElement
{
public:
    PRElement() = default;

    virtual ~PRElement() = default;

    virtual void GenElement(QDomElement &node, PRDoc *parent, PRLuaMain *lins) = 0;
    virtual void DrawElement(QWidget *widget) = 0;
    virtual void ElementDebug(){};
    virtual void BindCallBack(const QString& funcName) = 0;

public:
    static PRElement* CreateElement(const QString& type);

protected:
    PRElement(const PRElement&) = default; // 添加拷贝构造函数
    PRElement& operator=(const PRElement&) = default; // 添加赋值操作符

};

}

#endif // PRREADER_H
