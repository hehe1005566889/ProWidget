#include "ui/MainWindow.h"

#include <QApplication>
#include <QMainWindow>

#include "ui/WindowContainer.h"

#include "globals.h"


using namespace prml;

// Edit It For Your Compile Platform
// - MACOS for macintosh platform
// - WINNT for window platform
// #define PlatForm MACOS

int main(int argc, char *argv[])
{


    APP_CATCHER({

        QApplication a(argc, argv);
        QApplication::setAttribute(Qt::AA_DontUseNativeMenuBar, false);

        auto wc = new PWWindowContainer(new MainWindow());
        wc->show();
        a.exec();

    });
    return 0;
}
