#include "WindowContainer.h"

#include <QHBoxLayout>
#include <QLayout>

#include "platforms/PWMenuBar.h"


#ifdef MACOS
#include "platforms/MacOSWindowHelper.h"
#endif

PWWindowContainer::PWWindowContainer(QWidget *content, QWidget *parent)
    : QMainWindow(parent)
{

    this->resize(800, 450);
#ifdef MACOS
    // Attach MacOS Native Window Style
    MacOSWindowHelper::Apply(this);
#endif

    this->setCentralWidget(content);

    // SetUp MenuBar
    auto bar = new PWMenuBar(this);
    bar->AddMenu("文件", { "打开地址" });
    connect(bar, &PWMenuBar::OnMenuAction, this, &PWWindowContainer::on_menubar_callback);
    bar->Show();
}

void PWWindowContainer::on_menubar_callback(const QString &name)
{
    Info(name);
}
