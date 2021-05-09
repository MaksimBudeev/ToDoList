#pragma once

#include <QWidget>
#include <QVector>

class QListWidget;
class TaskInputDialog;
class Node;

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

private slots:
    void addedTask(const Node&);

private:
    QListWidget* tasksListWidget;
    TaskInputDialog* inputDialog;
};

