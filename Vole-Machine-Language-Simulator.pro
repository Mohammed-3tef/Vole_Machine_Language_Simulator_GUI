QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/help.cpp \
    src/instructions.cpp \
    main.cpp \
    src/mainwindow.cpp \
    src/memory.cpp \
    src/register.cpp

HEADERS += \
    include/help.h \
    include/instructions.h \
    include/mainwindow.h \
    include/memory.h \
    include/register.h

FORMS += \
    form/help.ui \
    form/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

RC_FILE = app.rc

DISTFILES += \
    file/file.txt
