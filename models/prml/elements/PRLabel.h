#ifndef PRLABEL_H
#define PRLABEL_H

#include "models/prml/PRReader.h"
#include "models/lua/PRLua.h"
#include "models/prml/PRDoc.h"

#include <QLabel>

using namespace prlua;

namespace prml
{

class PRLabel : public PRElement
{
public:
    PRLabel() : PRElement(), _label(nullptr) {}
    ~PRLabel()
    {
        _label->close();
        delete _label;
    }

public:
    void GenElement(QDomElement &node, PRDoc *parent, PRLuaMain *lins)
    {
        _main = lins;

        QString content;
        content = FETCH_VALUE(node);

        _label = new QLabel();
        _label->setText(content);

        CHECK_ATTRI;
        FOREACH_ATTRIBUTE(_label, node, {
            if(item.nodeName() == "name")
            {
                CHECK_NAME(item.nodeValue());
                _id = item.nodeValue();
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _label->setParent(widget);
        _label->show();
    }

    void DrawElement() {
        Debug("[Element] PLabel Create Notify");
    }

    void BindCallBack(const QString& funcName)
    {
        Debug("[Element] On Bind Call Back " + funcName);
        _main->CallLuaFunction(funcName, { 114514 });
    }

    QWidget* GetWidget()
    {
        return _label;
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
    QLabel* _label;
    PRLuaMain* _main;
    QString _id;

protected:
    PRLabel(const PRLabel&) = default; // 添加拷贝构造函数
    PRLabel& operator=(const PRLabel&) = default; // 添加赋值操作符

};

}


#endif // PRLABEL_H
