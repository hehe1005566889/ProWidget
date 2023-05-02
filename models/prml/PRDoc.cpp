#include "PRDoc.h"

#include "PRReader.h"
#include "globals.h"

namespace prml
{

PRDoc::PRDoc()
{
    _doc = create_ref<QDomDocument>();
}

PRDoc::PRDoc(const QString &doc)
{
    _doc = create_ref<QDomDocument>();
    if(!_doc->setContent(doc))
        THROW(PRMLEXCEP());
}

PRDoc::~PRDoc()
{
    Info("On PDoc Instance Delete");
    qDeleteAll(_elements);
    _elements.clear();
}

bool PRDoc::TreatRoot()
{
    if(_doc->isNull())
        return false;

    auto root = _doc->documentElement();
    if(root.tagName() != "pdoc")
        return false;

    return true;
}

void PRDoc::GetHeader()
{
    if(!TreatRoot())
        THROW(PRMLEXCEP());

    auto root = _doc->documentElement();
    _header.Map = root.attributes();
}

void PRDoc::ReadElement()
{
    auto docs = _doc->documentElement().childNodes();
    for(int i = 0; i <= docs.count() - 1; i++)
    {
        auto item = docs.at(i).toElement();
        auto name = item.nodeName();

        auto element = PRElement::CreateElement(name);
        if(element == nullptr)
            continue;
        element->GenElement(item);
        _elements.append(element);
    }
}

void PRDoc::DrawElement(QWidget *widget)
{
    foreach (auto item, _elements)
    {
        item->Debug();
        item->DrawElement(widget);
    }
}

}
