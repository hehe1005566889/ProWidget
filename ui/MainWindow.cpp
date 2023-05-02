#include "MainWindow.h"

#include "models/editor/includes/Languages/QLuaCompleter.h"
#include "models/editor/includes/Languages/QLuaHighlighter.h"
#include "models/editor/includes/Languages/QXMLHighlighter.hpp"
#include "ui_MainWindow.h"

#include "platforms/PWMessageBox.h"

#include "models/lua/PRLuaLib.hpp"

MainWindow* MainWindow::Instance;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set Global Instance
    Instance = this;
    // ===================

    _ui_editor = create_ref<QCodeEditor>(ui->xml_editor_display);
    _code_editor = create_ref<QCodeEditor>(ui->code_bck);

    ui->xml_editor_display->layout()->addWidget(_ui_editor.get());
    ui->code_bck->layout()->addWidget(_code_editor.get());

    auto font = _ui_editor->font();
    font.setPixelSize(18);
    _ui_editor->setFont(font);
    _code_editor->setFont(font);

    _ui_editor->setHighlighter(new QXMLHighlighter());

    _code_editor->setHighlighter(new QLuaHighlighter());
    _code_editor->setCompleter(new QLuaCompleter());

    _ui_editor->setTabReplace(true);
    _code_editor->setTabReplace(true);

    _ui_editor->show();
    _code_editor->show();


    // Init PRLuaMain
    _lua_main = create_ref<PRLuaMain>();
    _lua_main->LoadLibs();
    prlua::InitLuaLib(_lua_main);
    prlua::onLuaPrint = [](const QString& log)
    {
        Instance->ui->console_output->append(log);
    };


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadDoc(const PWProject &project)
{
    PWMessageBox::Basic("Project Loaded", " Project Name : " + project.Name + "\n Project Author : " + project.Author + "\n");
    this->_ui_editor->append(project.indexPageContent);
    this->_code_editor->append(project.mainCodeContent);
}


// Run The PWML UI In A New Widget Window
void MainWindow::RunInNewWidget()
{
    auto text = _ui_editor->document()->toPlainText();
    if(text.isNull() || text.isEmpty())
        PWMessageBox::Critical("Code Is Null Or Empty", "Code Is Null Or Empty");

    CATCHER({
        PWMessageBox::Critical("Code Is Vaild", "Error");
    }, {
        _doc = create_ref<PRDoc>(text, _lua_main.get());
        if(!_doc->TreatRoot())
            PWMessageBox::Critical("Code Is InValid", "Error");

        _doc->GetHeader();
        _doc->ReadElement();
        auto widget = new QWidget(nullptr);
        _doc->DrawElement(widget);
        widget->show();
    })
}
// ======================================



void MainWindow::on_pushButton_clicked()
{
    auto text = _ui_editor->document()->toPlainText();
    if(text.isNull() || text.isEmpty())
        PWMessageBox::Critical("Code Is Null Or Empty", "Code Is Null Or Empty");

    CATCHER({
        PWMessageBox::Critical("Code Is Vaild", "Error");
    }, {
        _doc = create_ref<PRDoc>(text, _lua_main.get());
        if(!_doc->TreatRoot())
            PWMessageBox::Critical("Code Is InValid", "Error");

        _doc->GetHeader();
        _doc->ReadElement();
        _doc->DrawElement(ui->display);

        _lua_main->PushAndCall(_code_editor->document()->toPlainText());
    })
}


void MainWindow::on_console_input_returnPressed()
{
    auto code = ui->console_input->text();

    QString text("> [#Code]");
    text.replace("[#Code]", ui->console_input->text());

    ui->console_output->append(text);
    ui->console_input->setText("");

    _lua_main->PushAndCall(code);
}
