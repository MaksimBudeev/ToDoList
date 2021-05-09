#include "todolistwidget.h"
#include "taskinputwindow.h"
#include "Node.h"
#include "listitemwidget.h"

#include <QVBoxLayout>
#include <QListWidget>
#include <QDebug>

enum TaskRoles
{
    TaskText = Qt::UserRole + 1,
    TaskDate = Qt::UserRole + 2,
    TaskPriority = Qt::UserRole + 3
};

ToDoListWidget::ToDoListWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vBox = new QVBoxLayout(this);
    tasksListWidget = new QListWidget(this);

    vBox->addWidget(tasksListWidget);
}

void ToDoListWidget::createTask()
{
    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Node&)), this, SLOT(addedTask(const Node&)));
    inputDialog->open();
    qDebug() << "Create task";
}

void ToDoListWidget::editTask()
{
    qDebug() << "Edit task";
}

void ToDoListWidget::compliteTask()
{
    qDebug() << "complite task";
}

void ToDoListWidget::deleteTask()
{
    qDebug() << "Delete task";
}

void ToDoListWidget::setTaskPriority(int priority)
{
    qDebug() << "Set priority:" << priority;
}

void ToDoListWidget::addedTask(const Node& newTask)
{
    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Node&)), this, SLOT(addedTask(const Node&)));

    QListWidgetItem* taskItem = new QListWidgetItem(tasksListWidget);
    tasksListWidget->addItem(taskItem);
    QString taskText = QString::fromStdString(newTask.GetText());
    QString dateText = QString::fromStdString(newTask.GetDate());
    taskItem->setData(TaskText, taskText);
    taskItem->setData(TaskDate, dateText);
    taskItem->setData(TaskPriority, newTask.GetPriority());
    ListItemWidget* listItemWidget = new ListItemWidget(taskText, dateText, tasksListWidget);
    taskItem->setSizeHint(listItemWidget->sizeHint());
    tasksListWidget->setItemWidget(taskItem, listItemWidget);

}
