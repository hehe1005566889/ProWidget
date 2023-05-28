#include "PRReader.h"

#include "models/prml/elements/PRButton.h"
#include "models/prml/elements/PRLabel.h"

#include "PRMLTools.hpp"

namespace prml
{

void PRElement::SetWidgetDomAttributes(QWidget *widget, const QString &key, const QString &value)
{
    if(key == "pos")
    {
        Debug("On Dom Move Element");

        int x = 0, y = 0;
        PRMLTools::ParsePos(value, x, y);
        widget->move(x, y);
    }
    if(key == "style")
    {
        Debug("On Dom Set Style");

        widget->setStyleSheet(value);
    }
    if(key == "size")
    {
        Debug("On Dom Change Size");

        int w = 0, h = 0;
        PRMLTools::ParsePos(value, w, h);
        widget->resize(w, h);
    }
}

void PRElement::SetWidgetAttributes(QWidget *widget, const QString &node, const QString &value)
{
    if(node == "pos")
    {
        int x = 0, y = 0;
        PRMLTools::ParsePos(value, x, y);
        widget->move(x, y);
    }
    if(node == "size")
    {
        int w = 0, h = 0;
        PRMLTools::ParsePos(value, w, h);
        widget->resize(w, h);
    }
    if(node == "enable")
    {
        bool res;
        PRMLTools::ParseBoolean(value, res);
        if(res)
            widget->setEnabled(true);
        else
            widget->setDisabled(true);
    }
    if(node == "visible")
    {
        bool res;
        PRMLTools::ParseBoolean(value, res);
        widget->setHidden(!res);
    }
    if(node == "style")
    {
        widget->setStyleSheet(value);
    }
}

void PRElement::DealScriptCreateArgs(QWidget *widget, const QList<QString> &args, std::function<void(const QString& key,const QString& value)> callback)
{
    for(const auto &arg : args) {

        if(!arg.contains("="))
            continue;
        auto kv = arg.split("=");
        if(kv.size() != 2)
            continue;

        SetWidgetAttributes(widget, kv[0], kv[1]);
        callback(kv[0], kv[1]);
    }
}

PRElement* PRElement::CreateElement(const QString &type)
{
    if(type == "button")
        return new PRButton();
    if(type == "label")
        return new PRLabel();
    return nullptr;
}

}
