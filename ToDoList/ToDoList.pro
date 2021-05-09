QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/Node.cpp \
    ../src/prioritysetwidget.cpp \
    ../src/taskinputwindow.cpp \
    ../src/todolistwidget.cpp \
    controlwidget.cpp \
    main.cpp \
    mymainwindow.cpp

HEADERS += \
    ../src/Node.h \
    ../src/prioritysetwidget.h \
    ../src/taskinputwindow.h \
    ../src/todolistwidget.h \
    controlwidget.h \
    mymainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
