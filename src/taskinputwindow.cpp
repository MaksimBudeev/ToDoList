#include "taskinputwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QFormLayout>
#include <QStringList>
#include <QDialogButtonBox>

TaskInputDialog::TaskInputDialog(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(300, 200);

    taskLineEdit = new QLineEdit(this);
    dateLineEdit = new QLineEdit(this);
    priorityComboBox = new QComboBox(this);

    QStringList priorityList;
    priorityList << "1" << "2" << "3" << "4" << "5";
    priorityComboBox->addItems(priorityList);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);

    QFormLayout* dialogLayout = new QFormLayout();
    dialogLayout->addRow("Task:", taskLineEdit);
    dialogLayout->addRow("Date:", dateLineEdit);
    dialogLayout->addRow("Priority:", priorityComboBox);
    dialogLayout->addRow("", buttonBox);

    setLayout(dialogLayout);
}
