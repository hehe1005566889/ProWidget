#ifdef MACOS

#include "MacOSWindowHelper.h"

#if defined(Q_OS_MAC)

#include <AppKit/AppKit.h>
#include <AppKit/NSMenu.h>
#include <AppKit/NSMenuItem.h>
#include <AppKit/AppKit.h>

#include <QIcon>

#import "libraries/MacHelper/src/MacHelper.h"
#import "libraries/MacHelper/src/MacToolbar.h"
#import "libraries/MacHelper/src/MacMenubarIcon.h"

void MacOSWindowHelper::Apply(QWidget *widget)
{
    NSWindow *window = [(NSView*)widget->winId() window];
window.title = @"ProWidget Editor MacOS";

Nedrysoft::MacHelper::MacToolbar toolbar;
QIcon qtIcon(QStringLiteral(":qtlogo.png"));
//toolbar.addItem(qtIcon,"","");
toolbar.attachToWindow(widget);


}

#endif // Q_OS_MAC

#endif
