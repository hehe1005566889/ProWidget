#ifndef PRDOC_H
#define PRDOC_H

#include "globals.h"
#include <QDomDocument>
#include <QList>

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
    PRDoc(const QString& doc);

    ~PRDoc();

public:
    bool TreatRoot();
    void GetHeader();
    void ReadElement();
    void DrawElement(QWidget *widget);

private:
    ref<QDomDocument> _doc;
    QList<PRElement*> _elements;
    PDocHeader _header;
};

}

#endif // PRDOC_H
