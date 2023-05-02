#ifndef QHIGHLIGHTBLOCKRULE_H
#define QHIGHLIGHTBLOCKRULE_H


// Qt
#include <QRegularExpression>
#include <QString>

struct QHighlightBlockRule
{
    QHighlightBlockRule() :
        startPattern(),
        endPattern(),
        formatName()
    {}

    QHighlightBlockRule(QRegularExpression start, QRegularExpression end, QString format) :
        startPattern(std::move(start)),
        endPattern(std::move(end)),
        formatName(std::move(format))
    {}

    QRegularExpression startPattern;
    QRegularExpression endPattern;
    QString formatName;
};

#endif // QHIGHLIGHTBLOCKRULE_H
