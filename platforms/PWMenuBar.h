#ifndef PWMENUBAR_H
#define PWMENUBAR_H

#include <QMainWindow>
#include <QMenuBar>
#include "globals.h"

#include <initializer_list>

class PWMenuBar : public QObject
{
    Q_OBJECT
public:
    PWMenuBar(QMainWindow* widget);
    ~PWMenuBar();

    void AddMenu(const QString& menu, std::initializer_list<const char*> sublists);
    void Show();
    void Hide();

signals:
    void OnMenuAction(const QString& text);

private slots:
    void onAction();

private:
    QMainWindow* parent;
    QMenuBar* bar;
};

#endif // PWMENUBAR_H
