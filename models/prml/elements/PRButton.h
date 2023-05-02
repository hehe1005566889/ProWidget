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
        FOREACH_ATTRIBUTE(node, {
            if (item.nodeName() == "style") {
                _button->setStyleSheet(item.nodeValue());
            }
            if(item.nodeName() == "pos")
            {
                CHECK_POS(_button, item.nodeValue());
            }
            if(item.nodeName() == "name")
            {
                CHECK_NAME(item.nodeValue());
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _button->setParent(widget);
        _button->show();
    }

    void DrawElement() {
        Info("PButton Create Notify");
    }

    void BindCallBack(const QString& funcName)
    {
        Debug("On Bind Call Back " + funcName);
        _main->CallLuaFunction(funcName, { 114514 });
    }

private:
    QPushButton* _button;
    PRLuaMain *_main;

protected:
    PRButton(const PRButton&) = default; // 添加拷贝构造函数
    PRButton& operator=(const PRButton&) = default; // 添加赋值操作符

};

}

#endif // PRBUTTON_H
