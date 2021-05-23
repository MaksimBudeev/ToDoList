#include "todolistwidget.h"
#include "taskinputwindow.h"
#include "Task.h"
#include "listitemwidget.h"

#include <QVBoxLayout>
#include <QListWidget>
#include <QDebug>
#include <QVariant>

enum TaskRoles
{
    TaskText = Qt::UserRole + 1,
    TaskDate = Qt::UserRole + 2,
    TaskPriority = Qt::UserRole + 3,
    TaskStatus = Qt::UserRole + 4
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
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(addedTask(const Task&)));
    inputDialog->open();
    qDebug() << "Create task";
}

void ToDoListWidget::editTask()
{
    if (!tasksListWidget->currentItem())
    {
        return;
    }

    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(editingTask(const Task&)));

    QString taskText = tasksListWidget->currentItem()->data(TaskText).toString();
    QString taskDate = tasksListWidget->currentItem()->data(TaskDate).toString();
    int taskPriority = tasksListWidget->currentItem()->data(TaskPriority).toInt();
    Task editableTask(taskDate.toStdString(), taskText.toStdString(), taskPriority);

    inputDialog->setTaskData(editableTask);
    qDebug() << "Edit task";

    inputDialog->open();
}

void ToDoListWidget::editingTask(const Task& node)
{
    QString taskText = QString::fromStdString(node.getText());
    QString dateText = QString::fromStdString(node.getDate());
    int priority = node.getPriority();

    auto taskItem = tasksListWidget->currentItem();

    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString oldTaskText = task[0].toString();
    QString oldTaskDate = task[1].toString();
    int oldTaskPriority = task[2].toInt();

    Task editableTask(oldTaskDate.toStdString(), oldTaskText.toStdString(), oldTaskPriority);

    taskItem->setData(TaskText, taskText);
    taskItem->setData(TaskDate, dateText);
    taskItem->setData(TaskPriority, priority);

    tasksListWidget->removeItemWidget(tasksListWidget->currentItem());
    tasksListWidget->setItemWidget(taskItem, new ListItemWidget(taskText, dateText, tasksListWidget));
}

void ToDoListWidget::compliteTask()
{
    if (tasksListWidget->currentItem() == nullptr || tasksListWidget->currentItem()->data(TaskStatus) != true)
    {
        return;
    }

    qDebug() << "complite task";
    tasksListWidget->currentItem()->setBackgroundColor(QColor(0, 250, 0));

    auto taskItem = tasksListWidget->currentItem();
    taskItem->setData(TaskStatus, true);
    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString taskText = task[0].toString();
    QString taskDate = task[1].toString();
    int taskPriority = task[2].toInt();
    Task complitedTask(taskDate.toStdString(), taskText.toStdString(), taskPriority);

    if (tasksStorage.indexOf(complitedTask, 0) != -1)
    {
        tasksStorage.remove(tasksStorage.indexOf(complitedTask));
    }
}

void ToDoListWidget::deleteTask()
{
    if (tasksListWidget->currentItem() == nullptr)
    {
        return;
    }

    auto taskItem = tasksListWidget->currentItem();
    taskItem->setData(TaskStatus, true);
    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString taskText = task[0].toString();
    QString taskDate = task[1].toString();
    int taskPriority = task[2].toInt();
    Task deletedTask(taskDate.toStdString(), taskText.toStdString(), taskPriority);

    tasksListWidget->removeItemWidget(tasksListWidget->currentItem());
    delete tasksListWidget->takeItem(tasksListWidget->currentRow());
    qDebug() << "Delete task";
}

void ToDoListWidget::setTaskPriority(int priority)
{
    for (int i = 0; i < tasksListWidget->count(); i++)
    {
        auto item = tasksListWidget->item(i);
        if (item->data(TaskPriority) != priority)
        {
            item->setHidden(true);
        }
        else
        {
            item->setHidden(false);
        }
    }
    qDebug() << "Set priority:" << priority;
}

void ToDoListWidget::addedTask(const Task& newTask)
{
    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(addedTask(const Task&)));

    QListWidgetItem* taskItem = new QListWidgetItem(tasksListWidget);
    tasksListWidget->addItem(taskItem);
    QString taskText = QString::fromStdString(newTask.getText());
    QString dateText = QString::fromStdString(newTask.getDate());

    taskItem->setData(TaskText, taskText);
    taskItem->setData(TaskDate, dateText);
    taskItem->setData(TaskPriority, newTask.getPriority());
    taskItem->setData(TaskStatus, false);

    ListItemWidget* listItemWidget = new ListItemWidget(taskText, dateText, tasksListWidget);
    taskItem->setSizeHint(listItemWidget->sizeHint());
    tasksListWidget->setItemWidget(taskItem, listItemWidget);

    tasksStorage.push_back(newTask);
}
