#pragma once

#include <QDialog>

class QComboBox;
class QLineEdit;
class QFormLayout;
class Node;

class TaskInputDialog: public QDialog
{
    Q_OBJECT
public:
    TaskInputDialog(QWidget *parent = nullptr);
    void setTaskData(const Node& taskInfo);

signals:
    void taskInfoSended(const Node&);

public slots:
    void sendTaskData();

private:
    QLineEdit* taskLineEdit = nullptr;
    QLineEdit* dateLineEdit = nullptr;
    QComboBox* priorityComboBox = nullptr;
};
