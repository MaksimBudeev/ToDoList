#pragma once

#include <QDialog>

class QComboBox;
class QLineEdit;
class QFormLayout;

class TaskInputDialog: public QDialog
{
    Q_OBJECT
public:
    TaskInputDialog(QWidget *parent = nullptr);

private:
    QLineEdit* taskLineEdit = nullptr;
    QLineEdit* dateLineEdit = nullptr;
    QComboBox* priorityComboBox = nullptr;
};
