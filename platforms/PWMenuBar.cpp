#include "PWMenuBar.h"

#include <QLayout>

PWMenuBar::PWMenuBar(QMainWindow *widget)
    : QObject(widget)
{
    parent = widget;
    bar = new QMenuBar(widget);
}

PWMenuBar::~PWMenuBar()
{
    bar->clear();
    delete bar;
}

void PWMenuBar::AddMenu(const QString &menu, std::initializer_list<const char *> sublists)
{
    QMenu* fileMenu = new QMenu(menu, bar);

    for(auto item : sublists)
    {
        QAction* openAction = new QAction(item, parent);
        QObject::connect(openAction, &QAction::triggered, this, &PWMenuBar::onAction);
        fileMenu->addAction(openAction);
    }

    bar->addMenu(fileMenu);
}

void PWMenuBar::Show()
{
    parent->setMenuBar(bar);
    bar->show();
}

void PWMenuBar::Hide()
{
    bar->close();
}

void PWMenuBar::onAction()
{
    QObject* senderObj = QObject::sender();
    if (senderObj)
    {
        // 使用 qobject_cast 将对象转换为 QPushButton
        auto action = qobject_cast<QAction*>(senderObj);

        Q_EMIT OnMenuAction(action->text());
    }
}
