#ifndef PRCANVAS_H
#define PRCANVAS_H

#include "models/prml/PRReader.h"
#include "models/lua/PRLua.h"
#include "models/prml/PRDoc.h"

#include <QWidget>

using namespace prlua;

namespace prml
{

class PRCanvas : public PRElement
{
public:
    PRCanvas() : PRElement(), _widget(nullptr) {}
    ~PRCanvas()
    {
        _widget->close();
        delete _widget;
    }

public:

    void OnScriptCreate(const QList<QString>& args) {

    }

    void GenElement(QDomElement &node, PRDoc *parent, PRLuaMain *lins)
    {
        _main = lins;

        QString content;
        content = FETCH_VALUE(node);

        _widget = new QWidget();

        CHECK_ATTRI;
        FOREACH_ATTRIBUTE(_widget, node, {
            if(item.nodeName() == "name")
            {
                CHECK_NAME(item.nodeValue());
                _id = item.nodeValue();
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _widget->setParent(widget);
        _widget->show();
    }

    void DrawElement() {
        Debug("[Element] PLabel Create Notify");
    }

    void BindCallBack(const QString& funcName)
    {
        //Debug("[Element] On Bind Call Back " + funcName);
        //_main->CallLuaFunction(funcName, { 114514 });
    }

    QWidget* GetWidget()
    {
        return _widget;
    }


    void SetAttribute(const QString& key, const QString& value)
    {
        Debug("[Element] Type : PLable -> Attribute Key : " + key + " Value : " + value);
    }

    const QString ElementNameDebug() const
    {
        Debug("[Element] Type : PLabel");
        return _id;
    }

private:
    QWidget* _widget;
    PRLuaMain* _main;
    QString _id;

protected:
    PRCanvas(const PRCanvas&) = default; // 添加拷贝构造函数
    PRCanvas& operator=(const PRCanvas&) = default; // 添加赋值操作符

};

}

#endif // PRCANVAS_H
