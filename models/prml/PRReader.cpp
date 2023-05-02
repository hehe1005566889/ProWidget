#include "PRReader.h"

#include "models/prml/elements/PRButton.h"

namespace prml
{

PRElement* PRElement::CreateElement(const QString &type)
{
    if(type == "button")
        return new PRButton();
    return nullptr;
}

}
