#ifndef QGLSLHIGHLIGHTER_HPP
#define QGLSLHIGHLIGHTER_HPP


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
class QGLSLHighlighter : public QStyleSyntaxHighlighter
{
    Q_OBJECT
public:

    /**
     * @brief Constructor.
     * @param document Pointer to document.
     */
    explicit QGLSLHighlighter(QTextDocument* document=nullptr);

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



#endif // QGLSLHIGHLIGHTER_HPP
