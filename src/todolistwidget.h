#pragma once

#include <QWidget>
#include <QVector>

class QListWidget;

class ToDoListWidget: public QWidget
{
    Q_OBJECT
public:
    ToDoListWidget(QWidget *parent = nullptr);

public slots:
    void createTask();
    void editTask();
    void deleteTask();
    void compliteTask();
    void setTaskPriority(int);

private:
    QListWidget* tasksListWidget;
};

