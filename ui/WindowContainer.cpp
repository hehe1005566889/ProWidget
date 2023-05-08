#include "WindowContainer.h"

#include <QHBoxLayout>
#include <QLayout>
#include <QFileDialog>

#include "platforms/PWMenuBar.h"
#include "platforms/PWMessageBox.h"

#include "MainWindow.h"
#include "models/files/PWProjectLoader.h"

using namespace pwfile;

#ifdef MACOS
#include "platforms/MacOSWindowHelper.h"
#endif

PWWindowContainer::PWWindowContainer(QWidget *content, QWidget *parent)
    : QMainWindow(parent)
{
    mainWindow = qobject_cast<MainWindow*>(content);
    this->resize(800, 450);
#ifdef MACOS
    // Attach MacOS Native Window Style
    MacOSWindowHelper::Apply(this);
#endif

    this->setCentralWidget(content);

    // SetUp MenuBar
    auto bar = new PWMenuBar(this);
    bar->AddMenu("文件", { "打开地址" });
    bar->AddMenu("项目", { "运行" });
    connect(bar, &PWMenuBar::OnMenuAction, this, &PWWindowContainer::on_menubar_callback);
    bar->Show();
}

void PWWindowContainer::on_menubar_callback(const QString &name)
{
    Info(name);
    if(name == "打开地址")
    {
        mainWindow->ReleaseEnv();

        QString folderPath = QFileDialog::getExistingDirectory(nullptr, "Select Folder", QDir::homePath());
        if (!folderPath.isEmpty()) {
            PWProject project;
            PWProjectLoader loader(folderPath);
            if(!loader.Read())
                PWMessageBox::Critical("Error", "Can't Find Index File In This Folder");
            else
            {
                loader.ReadFolder(project);
                mainWindow->LoadDoc(project);
            }
        }
    }
    if(name == "运行")
    {
        mainWindow->RunInNewWidget();
    }

}
