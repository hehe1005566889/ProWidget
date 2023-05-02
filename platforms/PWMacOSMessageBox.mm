#ifdef MACOS

#include "PWMessageBox.h"

#import <Cocoa/Cocoa.h>


void PWMessageBox::Basic(const QString& title, const QString& content)
{

    NSAlert *alert = [[NSAlert alloc] init];

    [alert setMessageText:[NSString stringWithUTF8String:title.toUtf8().constData()]];
    [alert setInformativeText:[NSString stringWithUTF8String:content.toUtf8().constData()]];

    [alert setAlertStyle:NSAlertStyleInformational];

    [alert addButtonWithTitle:@"OK"];

    [alert runModal];
}

void PWMessageBox::Critical(const QString &title, const QString &content)
{

    NSAlert *alert = [[NSAlert alloc] init];

    // 设置对话框标题和消息文本
    [alert setMessageText:[NSString stringWithUTF8String:title.toUtf8().constData()]];
    [alert setInformativeText:[NSString stringWithUTF8String:content.toUtf8().constData()]];
    [alert setAlertStyle:NSAlertStyleCritical];
    [alert addButtonWithTitle:@"OK"];

    [alert runModal];
}

void PWMessageBox::Warning(const QString &title, const QString &content)
{

    NSAlert *alert = [[NSAlert alloc] init];

    [alert setMessageText:[NSString stringWithUTF8String:title.toUtf8().constData()]];
    [alert setInformativeText:[NSString stringWithUTF8String:content.toUtf8().constData()]];

    [alert setAlertStyle:NSAlertStyleWarning];

    [alert addButtonWithTitle:@"OK"];
    [alert runModal];
}


#endif
