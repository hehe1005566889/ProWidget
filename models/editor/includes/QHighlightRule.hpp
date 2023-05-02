#ifndef QHIGHLIGHTRULE_HPP
#define QHIGHLIGHTRULE_HPP


// Qt
#include <QRegularExpression>
#include <QString>

struct QHighlightRule
{
    QHighlightRule() :
        pattern(),
        formatName()
    {}

    QHighlightRule(QRegularExpression p, QString f) :
        pattern(std::move(p)),
        formatName(std::move(f))
    {}

    QRegularExpression pattern;
    QString formatName;
};

#endif // QHIGHLIGHTRULE_HPP
