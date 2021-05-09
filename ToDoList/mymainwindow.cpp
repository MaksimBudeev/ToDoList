#include "mymainwindow.h"
#include "controlwidget.h"
#include "D:\cw-iv-023_todo-list\src\prioritysetwidget.h"
#include "D:\cw-iv-023_todo-list\src\todolistwidget.h"

#include <QHBoxLayout>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QWidget(parent)
{
    ControlWidget * controlWidget = new ControlWidget();
    ToDoListWidget * taskList = new ToDoListWidget();

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(controlWidget);
    mainLayout->addWidget(taskList, 5);

    setLayout(mainLayout);
}

