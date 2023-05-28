#include "PRDoc.h"

#include "PRReader.h"
#include "globals.h"

namespace prml
{

PRDoc::PRDoc(PRLuaMain* main)
{
    _doc = create_ref<QDomDocument>();
    _main = main;
}

PRDoc::PRDoc(const QString &doc, PRLuaMain* main)
{
    _doc = create_ref<QDomDocument>();
    _main = main;
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
        element->GenElement(item, this, _main);
        _elements.append(element);
    }
}

void PRDoc::DrawElement(QWidget *widget)
{
    _last_parent_widget = widget;

    foreach (auto item, _elements)
    {
        item->ElementDebug();
        item->DrawElement(widget);
    }
}

void PRDoc::PushItem(PRElement *item, const QList<QString>& args)
{
    if(item == nullptr)
        return;

    item->OnScriptCreate(args);
    _elements.append(item);
    if(_last_parent_widget == nullptr)
    {
        Error("This Doc IS NOT ATTENDED!");
        THROW(PWDocEXCP());
    }
    item->DrawElement(_last_parent_widget);
}

void PRDoc::RegisterNamedItem(const QString &name, PRElement *item)
{
    if(_named_items.contains(name))
    {
        Error("[Dom] Item Has Registered Before");
        return;
    }
    Debug("[Dom] Registered Item -> " + name);
    _named_items.insert(name, item);
}

bool PRDoc::FetchItem(const QString &name, PRElement *&element)
{
    if(!_named_items.contains(name))
    {
        Error("[Dom] Can't Find This Control");
        element = nullptr;
        return false;
    }
    Debug("[Dom] Fetched Item -> " + name);
    element = _named_items.value(name);

    return true;
}

}
