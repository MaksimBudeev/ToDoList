#include "mymainwindow.h"
#include "controlwidget.h"
#include "D:\cw-iv-023_todo-list\src\prioritysetwidget.h"
#include "D:\cw-iv-023_todo-list\src\todolistwidget.h"
// temporarily

#include <QHBoxLayout>

MyMainWindow::MyMainWindow(QWidget *parent)
    : QWidget(parent)
{
    ControlWidget * controlWidget = new ControlWidget();
    ToDoListWidget * taskList = new ToDoListWidget();
    PrioritySetWidget * setPriority = new PrioritySetWidget();

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(controlWidget);
    mainLayout->addWidget(taskList, 5);
    mainLayout->addWidget(setPriority);

    connect(controlWidget, SIGNAL(createTaskRequested()), taskList, SLOT(createTask()));
    connect(controlWidget, SIGNAL(editTaskRequested()), taskList, SLOT(editTask()));
    connect(controlWidget, SIGNAL(compliteTaskRequested()), taskList, SLOT(compliteTask()));
    connect(controlWidget, SIGNAL(deleteTaskRequested()), taskList, SLOT(deleteTask()));
    connect(setPriority, SIGNAL(priorityChangeRequested(int)), taskList, SLOT(setTaskPriority(int)));

    setLayout(mainLayout);
}
