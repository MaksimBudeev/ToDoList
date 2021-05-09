#include "controlwidget.h"

#include <QVBoxLayout>
#include <QPushButton>

ControlWidget::ControlWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);

    QPushButton *newTask = new QPushButton("Create new task", this);
    QPushButton *deleteTask = new QPushButton("Delete task", this);
    QPushButton *compliteTask = new QPushButton("Complite task", this);
    QPushButton *editTask = new QPushButton("Edit task", this);

    vbox->addWidget(newTask);
    vbox->addWidget(deleteTask);
    vbox->addWidget(compliteTask);
    vbox->addWidget(editTask);

    setLayout(vbox);

    connect(newTask, SIGNAL(clicked()), this, SIGNAL(createTaskRequested()));
}
