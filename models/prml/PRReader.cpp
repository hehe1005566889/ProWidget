#include "PRReader.h"

#include "models/prml/elements/PRButton.h"
#include "models/prml/elements/PRLabel.h"

namespace prml
{

PRElement* PRElement::CreateElement(const QString &type)
{
    if(type == "button")
        return new PRButton();
    if(type == "label")
        return new PRLabel();
    return nullptr;
}

}
