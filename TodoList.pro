QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/DataInput.cpp \
    ../src/Task.cpp \
    ../src/ControlWidget.cpp \
    ../src/ListItemWidget.cpp \
    ../src/main.cpp \
    ../src/MainWindow.cpp \
    ../src/PrioritySetWidget.cpp \
    ../src/TaskInputWindow.cpp \
    ../src/TodoListWidget.cpp

HEADERS += \
    ../src/DataInput.h \
    ../src/Task.h \
    ../src/ControlWidget.h \
    ../src/ListItemWidget.h \
    ../src/MainWindow.h \
    ../src/PrioritySetWidget.h \
    ../src/TaskInputWindow.h \
    ../src/TodoListWidget.h

DESTDIR = bin

