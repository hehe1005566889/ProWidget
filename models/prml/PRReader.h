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
#define FOREACH_ATTRIBUTE(widget, node, ...) \
for(int i = 0; i <= node.attributes().count() - 1; i++) \
{ \
    auto item = node.attributes().item(i); \
    SetWidgetAttributes(widget, item.nodeName(), item.nodeValue()); \
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

#define CHECK_DOM(WIDGET,KEY,VALUE) \
SetWidgetDomAttributes(WIDGET,KEY,VALUE)

#define CHECK_SCRIPT_DOM(WIDGET,KVLIST, CALLBACK) \
DealScriptCreateArgs(WIDGET,KVLIST,CALLBACK)

class PRDoc;

class PRElement
{
public:
    PRElement() = default;

    virtual ~PRElement() = default;

    virtual void OnScriptCreate(const QList<QString>& args) = 0;
    virtual void GenElement(QDomElement &node, PRDoc *parent, PRLuaMain *lins) = 0;
    virtual void DrawElement(QWidget *widget) = 0;
    virtual void ElementDebug(){};
    virtual const QString ElementNameDebug() const = 0;
    virtual void BindCallBack(const QString& funcName) = 0;
    virtual QWidget* GetWidget() = 0;
    virtual void SetAttribute(const QString& key, const QString& value) = 0;

protected:
    void SetWidgetDomAttributes(QWidget* widget, const QString& key, const QString& value);
    void SetWidgetAttributes(QWidget* widget, const QString& node, const QString& value);
    void DealScriptCreateArgs(QWidget* widget, const QList<QString>& args, std::function<void(const QString& key,const QString& value)> callback);

public:
    static PRElement* CreateElement(const QString& type);

protected:
    PRElement(const PRElement&) = default; // 添加拷贝构造函数
    PRElement& operator=(const PRElement&) = default; // 添加赋值操作符

};

}

#endif // PRREADER_H
