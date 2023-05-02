#ifndef PRBUTTON_H
#define PRBUTTON_H

#include "models/prml/PRReader.h"

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
    void GenElement(QDomElement &node) {
        QString content;
        content = FETCH_VALUE(node);

        _button = new QPushButton();
        _button->setText(content);

        CHECK_ATTRI;
        FOREACH_ATTRIBUTE(node, {
            if (item.nodeName() == "style") {
                _button->setStyleSheet(item.nodeValue());
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _button->setParent(widget);
        _button->show();
    }

    void Debug() {
        Info("PButton Create Notify");
    }

private:
    QPushButton* _button;

protected:
    PRButton(const PRButton&) = default; // 添加拷贝构造函数
    PRButton& operator=(const PRButton&) = default; // 添加赋值操作符

};

}

#endif // PRBUTTON_H
