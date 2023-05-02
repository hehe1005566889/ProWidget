#ifndef MACOS

#include "PWMessageBox.h"

#ifdef PWWin
#include <windows.h>
#endif

#include <QMessageBox>

void PWMessageBox::Basic(const QString& title, const QString& content)
{

#ifdef PWWin
    MessageBox(NULL, TEXT(content.toStdString().c_str()), TEXT(title.toStdString().c_str()), MB_OK | MB_ICONINFORMATION);
#else
    QMessageBox::information(nullptr, title, content);
#endif
}

void PWMessageBox::Critical(const QString &title, const QString &content)
{

#ifdef PWWin
    MessageBox(NULL, TEXT(content.toStdString().c_str()), TEXT(title.toStdString().c_str()), MB_OK | MB_ICONERROR);
#else
    QMessageBox::critical(nullptr, title, content);
#endif
}

void PWMessageBox::Warning(const QString &title, const QString &content)
{

#ifdef PWWin
    MessageBox(NULL, TEXT(content.toStdString().c_str()), TEXT(title.toStdString().c_str()), MB_OK | MB_ICONWARNING);
#else
    QMessageBox::warning(nullptr, title, content);
#endif
}


#endif
