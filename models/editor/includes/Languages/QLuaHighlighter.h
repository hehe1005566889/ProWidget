#ifndef QLUAHIGHLIGHTER_H
#define QLUAHIGHLIGHTER_H

// QCodeEditor
#include <models/editor/includes/QStyleSyntaxHighlighter.hpp>
#include <models/editor/includes/QHighlightRule.hpp>
// Qt
#include <QRegularExpression>
#include <QVector>

class QSyntaxStyle;

/**
 * @brief Class, that describes Glsl code
 * highlighter.
 */
class QLuaHighlighter : public QStyleSyntaxHighlighter
{
    Q_OBJECT
public:

    /**
     * @brief Constructor.
     * @param document Pointer to document.
     */
    explicit QLuaHighlighter(QTextDocument* document=nullptr);

protected:
    void highlightBlock(const QString& text) override;

private:

    QVector<QHighlightRule> m_highlightRules;

    QRegularExpression m_includePattern;
    QRegularExpression m_functionPattern;
    QRegularExpression m_defTypePattern;

    QRegularExpression m_commentStartPattern;
    QRegularExpression m_commentEndPattern;
};

#endif // QLUAHIGHLIGHTER_H
