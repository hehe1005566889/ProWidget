#ifndef QCXXHIGHLIGHTER_HPP
#define QCXXHIGHLIGHTER_HPP


// QCodeEditor
#include "models/editor/includes/QStyleSyntaxHighlighter.hpp" // Required for inheritance
#include "models/editor/includes/QHighlightRule.hpp"

// Qt
#include <QRegularExpression>
#include <QVector>

class QSyntaxStyle;

/**
 * @brief Class, that describes C++ code
 * highlighter.
 */
class QCXXHighlighter : public QStyleSyntaxHighlighter
{
    Q_OBJECT
public:

    /**
     * @brief Constructor.
     * @param document Pointer to document.
     */
    explicit QCXXHighlighter(QTextDocument* document=nullptr);

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



#endif // QCXXHIGHLIGHTER_HPP
