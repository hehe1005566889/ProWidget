#ifndef WINDOWCONTAINER_H
#define WINDOWCONTAINER_H

#include <QMainWindow>

class MainWindow;

class PWWindowContainer : public QMainWindow
{
public:
    explicit PWWindowContainer(QWidget* content, QWidget* parent = nullptr);

public slots:
    void on_menubar_callback(const QString& name);

private:
    MainWindow* mainWindow;

};

#endif // WINDOWCONTAINER_H
