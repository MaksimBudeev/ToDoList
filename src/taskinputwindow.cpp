#include "taskinputwindow.h"
#include "Task.h"

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

    connect(buttonBox, SIGNAL(accepted()), this, SIGNAL(accepted()));
    connect(buttonBox, SIGNAL(rejected()), this, SIGNAL(rejected()));

    connect(this, SIGNAL(accepted()), this, SLOT(sendTaskData()));
    connect(this, SIGNAL(rejected()), this, SLOT(close()));

    setLayout(dialogLayout);
}

void TaskInputDialog::sendTaskData()
{
    QString taskText = taskLineEdit->text();
    QString taskDate = dateLineEdit->text();
    QString taskPriority = priorityComboBox->currentText();
    Task newTask(taskDate.toStdString(), taskText.toStdString(), taskPriority.toInt());
    emit taskInfoSended(newTask);
    taskLineEdit->clear();
    dateLineEdit->clear();
    priorityComboBox->setCurrentIndex(0);

    close();
}

void TaskInputDialog::setTaskData(const Task& taskInfo)
{
   taskLineEdit->setText(QString::fromStdString(taskInfo.GetText()));
   dateLineEdit->setText(QString::fromStdString(taskInfo.GetDate()));
   priorityComboBox->setCurrentText(QString::number(taskInfo.GetPriority()));
}
