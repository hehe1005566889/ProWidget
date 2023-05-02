#ifndef PRDOC_H
#define PRDOC_H

#include "globals.h"
#include <QDomDocument>
#include <QList>
#include <QMap>

#include "models/lua/PRLua.h"

using namespace prlua;

namespace prml
{

class PRElement;

struct PDocHeader
{
    QDomNamedNodeMap Map;
};

class PRDoc
{
public:
    PRDoc();
    PRDoc(PRLuaMain* main);
    PRDoc(const QString& doc, PRLuaMain* main);

    ~PRDoc();

public:
    bool TreatRoot();
    void GetHeader();
    void ReadElement();
    void DrawElement(QWidget *widget);

    void RegisterNamedItem(const QString& name, PRElement* item);
    bool FetchItem(const QString& name, PRElement*& element);

private:
    ref<QDomDocument> _doc;
    QList<PRElement*> _elements;

    QMap<QString, PRElement*> _named_items;

    PDocHeader _header;
    PRLuaMain* _main;
};

}

#endif // PRDOC_H
