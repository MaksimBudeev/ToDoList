#include "todolistwidget.h"

#include <QVBoxLayout>
#include <QListWidget>
#include <QDebug>

ToDoListWidget::ToDoListWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vBox = new QVBoxLayout(this);
    tasksListWidget = new QListWidget(this);

    vBox->addWidget(tasksListWidget);
}

void ToDoListWidget::createTask()
{
    qDebug() << "Create task";
}
