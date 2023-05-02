#include "models/editor/includes/Languages/QGLSLCompleter.hpp"
#include "models/editor/includes/QLanguage.hpp"

// Qt
#include <QStringListModel>
#include <QFile>

QGLSLCompleter::QGLSLCompleter(QObject *parent) :
    QCompleter(parent)
{
    // Setting up GLSL types
    QStringList list;

    QFile fl(":/languages/glsl.xml");

    if (!fl.open(QIODevice::ReadOnly))
    {
        return;
    }

    QLanguage language(&fl);

    if (!language.isLoaded())
    {
        return;
    }

    auto keys = language.keys();
    for (auto&& key : keys)
    {
        auto names = language.names(key);
        list.append(names);
    }

    setModel(new QStringListModel(list, this));
    setCompletionColumn(0);
    setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    setCaseSensitivity(Qt::CaseSensitive);
    setWrapAround(true);
}
