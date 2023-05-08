#include "PRReader.h"

#include "models/prml/elements/PRButton.h"
#include "models/prml/elements/PRLabel.h"

namespace prml
{

void PRElement::SetWidgetAttributes(QWidget *widget, const QString &node, const QString &value)
{
    if(node == "pos")
    {
        if(!value.contains(","))
            THROW(PWDocEXCP());
        auto xy = value.split(",");
        if(xy.count() != 2)
            THROW(PWDocEXCP());
        widget->move(xy[0].toInt(), xy[1].toInt());
    }
    if(node == "size")
    {
        if(!value.contains(","))
            THROW(PWDocEXCP());
        auto xy = value.split(",");
        if(xy.count() != 2)
            THROW(PWDocEXCP());
        widget->resize(xy[0].toInt(), xy[1].toInt());
    }
    if(node == "enable")
    {
        if(value == "true")
            widget->setEnabled(true);
        else
            widget->setDisabled(true);
    }
    if(node == "visible")
    {
        widget->setHidden(value == "false");
    }
    if(node == "style")
    {
        widget->setStyleSheet(value);
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
