QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    models/basic/Logger.cpp \
    models/editor/src/Languages/QCXXHighlighter.cpp \
    models/editor/src/Languages/QGLSLCompleter.cpp \
    models/editor/src/Languages/QGLSLHighlighter.cpp \
    models/editor/src/Languages/QLuaCompleter.cpp \
    models/editor/src/Languages/QLuaHighlighter.cpp \
    models/editor/src/Languages/QXMLHighlighter.cpp \
    models/editor/src/QCodeEditor.cpp \
    models/editor/src/QFramedTextAttribute.cpp \
    models/editor/src/QLanguage.cpp \
    models/editor/src/QLineNumberArea.cpp \
    models/editor/src/QStyleSyntaxHighlighter.cpp \
    models/editor/src/QSyntaxStyle.cpp \
    models/files/PWProjectLoader.cpp \
    models/lua/PRLua.cpp \
    models/lua/PRLuaLib.cpp \
    models/lua/lib/lapi.c \
    models/lua/lib/lauxlib.c \
    models/lua/lib/lbaselib.c \
    models/lua/lib/lcode.c \
    models/lua/lib/lcorolib.c \
    models/lua/lib/lctype.c \
    models/lua/lib/ldblib.c \
    models/lua/lib/ldebug.c \
    models/lua/lib/ldo.c \
    models/lua/lib/ldump.c \
    models/lua/lib/lfunc.c \
    models/lua/lib/lgc.c \
    models/lua/lib/linit.c \
    models/lua/lib/liolib.c \
    models/lua/lib/llex.c \
    models/lua/lib/lmathlib.c \
    models/lua/lib/lmem.c \
    models/lua/lib/loadlib.c \
    models/lua/lib/lobject.c \
    models/lua/lib/lopcodes.c \
    models/lua/lib/loslib.c \
    models/lua/lib/lparser.c \
    models/lua/lib/lstate.c \
    models/lua/lib/lstring.c \
    models/lua/lib/lstrlib.c \
    models/lua/lib/ltable.c \
    models/lua/lib/ltablib.c \
    models/lua/lib/ltests.c \
    models/lua/lib/ltm.c \
    models/lua/lib/lundump.c \
    models/lua/lib/lutf8lib.c \
    models/lua/lib/lvm.c \
    models/lua/lib/lzio.c \
    models/prml/PRDoc.cpp \
    models/prml/PRReader.cpp \
    platforms/PWMenuBar.cpp \
    platforms/PWMessageBox.cpp \
    ui/MainWindow.cpp \
    ui/WindowContainer.cpp

HEADERS += \
    api/include/PWPlugin.hpp \
    api/include/ProWidgetAPI.hpp \
    globals.h \
    models/basic/Config.hpp \
    models/basic/DumpTool.h \
    models/basic/Exceptions.hpp \
    models/basic/Logger.h \
    models/basic/PlatForm.h \
    models/editor/includes/Languages/QCXXHighlighter.hpp \
    models/editor/includes/Languages/QGLSLCompleter.hpp \
    models/editor/includes/Languages/QGLSLHighlighter.hpp \
    models/editor/includes/Languages/QLuaCompleter.h \
    models/editor/includes/Languages/QLuaHighlighter.h \
    models/editor/includes/Languages/QXMLHighlighter.hpp \
    models/editor/includes/QCodeEditor.hpp \
    models/editor/includes/QFramedTextAttribute.hpp \
    models/editor/includes/QHighlightBlockRule.hpp \
    models/editor/includes/QHighlightRule.hpp \
    models/editor/includes/QLanguage.hpp \
    models/editor/includes/QLineNumberArea.hpp \
    models/editor/includes/QStyleSyntaxHighlighter.hpp \
    models/editor/includes/QSyntaxStyle.hpp \
    models/files/PWProjectLoader.h \
    models/lua/PRLua.h \
    models/lua/PRLuaLib.hpp \
    models/lua/lib/lapi.h \
    models/lua/lib/lauxlib.h \
    models/lua/lib/lcode.h \
    models/lua/lib/lctype.h \
    models/lua/lib/ldebug.h \
    models/lua/lib/ldo.h \
    models/lua/lib/lfunc.h \
    models/lua/lib/lgc.h \
    models/lua/lib/ljumptab.h \
    models/lua/lib/llex.h \
    models/lua/lib/llimits.h \
    models/lua/lib/lmem.h \
    models/lua/lib/lobject.h \
    models/lua/lib/lopcodes.h \
    models/lua/lib/lopnames.h \
    models/lua/lib/lparser.h \
    models/lua/lib/lprefix.h \
    models/lua/lib/lstate.h \
    models/lua/lib/lstring.h \
    models/lua/lib/ltable.h \
    models/lua/lib/ltests.h \
    models/lua/lib/ltm.h \
    models/lua/lib/lua.h \
    models/lua/lib/luaconf.h \
    models/lua/lib/lualib.h \
    models/lua/lib/lundump.h \
    models/lua/lib/lvm.h \
    models/lua/lib/lzio.h \
    models/prml/PRDoc.h \
    models/prml/PRReader.h \
    models/prml/elements/PRButton.h \
    models/prml/elements/PRLabel.h \
    platforms/MacOSWindowHelper.h \
    platforms/PWMenuBar.h \
    platforms/PWMessageBox.h \
    ui/MainWindow.h \
    ui/WindowContainer.h

FORMS += \
    resource/ui/MainWindow.ui

macx: {
    # macOS 平台下的配置
DEFINES += MACOS

# Setup Objc And Cocoa Framework
QMAKE_OBJC = YES
QMAKE_LFLAGS += -framework Cocoa
QMAKE_LFLAGS += -ObjC
LIBS += -framework AppKit
# ==============================

SOURCES += \
# Library - MacHelper ========================
libraries/MacHelper/src/MacHelper.mm \
libraries/MacHelper/src/MacMenubarIcon.mm \
libraries/MacHelper/src/MacPopover.mm \
libraries/MacHelper/src/MacToolbar.mm \
libraries/MacHelper/src/MacToolbarItem.mm \
libraries/MacHelper/src/PopoverHelper.mm \
libraries/MacHelper/src/StatusbarHelper.mm \
libraries/MacHelper/src/ToolbarDelegate.mm \
# ============================================
# MacOS Window Tool ==========================
platforms/MacOSWindowHelper.mm \
platforms/PWMacOSMessageBox.mm \

# ============================================

HEADERS += \
# Library - MacHelper ========================
libraries/MacHelper/include/MacHelper \
libraries/MacHelper/include/MacMenubarIcon \
libraries/MacHelper/include/MacPopover \
libraries/MacHelper/include/MacToolbar \
libraries/MacHelper/include/MacToolbarItem \
libraries/MacHelper/src/MacHelper.h \
libraries/MacHelper/src/MacMenubarIcon.h \
libraries/MacHelper/src/MacPopover.h \
libraries/MacHelper/src/MacToolbar.h \
libraries/MacHelper/src/MacToolbarItem.h \
libraries/MacHelper/src/PopoverHelper.h \
libraries/MacHelper/src/StatusbarHelper.h \
libraries/MacHelper/src/ToolbarDelegate.h \
# ============================================

} else: {
    # 非 macOS 平台下的配置
}

CONFIG(debug, debug|release) {
    DEFINES += PWDebug
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/resources.qrc

DISTFILES += \
    docs/Docs.txt \
    resource/setting.ini
