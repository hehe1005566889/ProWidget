#ifndef PRBUTTON_H
#define PRBUTTON_H

#include "models/prml/PRReader.h"
#include "models/prml/PRDoc.h"

#include <QPushButton>

namespace prml
{

class PRButton : public PRElement
{
public:
    PRButton() : PRElement(), _button(nullptr) {}
    ~PRButton()
    {
        _button->close();
        delete _button;
    }

public:
    void GenElement(QDomElement &node, PRDoc *parent, PRLuaMain *lins)
    {
        _main = lins;

        QString content;
        content = FETCH_VALUE(node);

        _button = new QPushButton();
        _button->setText(content);

        CHECK_ATTRI;
        FOREACH_ATTRIBUTE(_button, node, {
            if(item.nodeName() == "name")
            {
                CHECK_NAME(item.nodeValue());
                _id = item.nodeValue();
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _button->setParent(widget);
        _button->show();
    }

    void DrawElement() {
        Info("[Element] PButton Create Notify");
    }

    void BindCallBack(const QString& funcName)
    {
        Debug("[Element] On Bind Call Back " + funcName);
        callback = funcName;

        QObject::connect(_button, &QPushButton::clicked, [&] {
            _main->CallLuaFunction(callback, { 1 });
        });
    }

    QWidget* GetWidget()
    {
        return _button;
    }

    void SetAttribute(const QString& key, const QString& value)
    {
        Debug("[Element] Attribute Key : " + key + " Value : " + value);
        if(key == "text")
        {
            _button->setText(value);
            Debug("[Element] Set New Text Value Done");
        }
    }

    const QString ElementNameDebug() const
    {
        Debug("[Element] Type : PButton");
        return _id;
    }

private:
    QPushButton* _button;
    PRLuaMain *_main;
    QString callback;
    QString _id;

protected:
    PRButton(const PRButton&) = default; // 添加拷贝构造函数
    PRButton& operator=(const PRButton&) = default; // 添加赋值操作符

};

}

#endif // PRBUTTON_H
