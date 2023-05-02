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
        FOREACH_ATTRIBUTE(node, {
            if (item.nodeName() == "style") {
                _label->setStyleSheet(item.nodeValue());
            }
            if(item.nodeName() == "pos")
            {
                CHECK_POS(_label, item.nodeValue());
            }
            if(item.nodeName() == "name")
            {
                CHECK_NAME(item.nodeValue());
            }
        });
    }

    void DrawElement(QWidget *widget)
    {
        _label->setParent(widget);
        _label->show();
    }

    void DrawElement() {
        Debug("PLabel Create Notify");
    }

    void BindCallBack(const QString& funcName)
    {
        Debug("On Bind Call Back " + funcName);
        _main->CallLuaFunction(funcName, { 114514 });
    }

private:
    QLabel* _label;
    PRLuaMain* _main;

protected:
    PRLabel(const PRLabel&) = default; // 添加拷贝构造函数
    PRLabel& operator=(const PRLabel&) = default; // 添加赋值操作符

};

}


#endif // PRLABEL_H
