#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "globals.h"
#include "models/editor/includes/QCodeEditor.hpp"
#include "models/lua/PRLua.h"
#include "models/prml/PRDoc.h"

#include "models/files/PWProjectLoader.h"

using namespace pwfile;
using namespace prml;
using namespace prlua;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadDoc(const PWProject& project);
    void RunInNewWidget();
    void FetchDoc(PRDoc *&val)
    { val = _doc.get(); }

private slots:
    void on_pushButton_clicked();

    void on_console_input_returnPressed();

private:
    ref<QCodeEditor> _ui_editor, _code_editor; //template for design later move it to own page
    ref<PRDoc> _doc; //template for test
    ref<PRLuaMain> _lua_main;

private:
    Ui::MainWindow *ui;

public:
    static MainWindow* Instance;
};
#endif // MAINWINDOW_H
