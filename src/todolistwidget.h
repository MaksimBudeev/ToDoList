#pragma once

#include <QWidget>
#include <QVector>

class QListWidget;

class ToDoListWidget: public QWidget
{
    Q_OBJECT
public:
    ToDoListWidget(QWidget *parent = nullptr);

private:
    QListWidget* tasksListWidget;
};

