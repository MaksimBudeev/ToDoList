#include "prioritysetwidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

const int countButton = 5;

PrioritySetWidget::PrioritySetWidget(QWidget* parent)
    : QWidget(parent)
{
    QLabel *priorityLabel = new QLabel("Priority:", this);

    QVBoxLayout *vBox = new QVBoxLayout(this);
    vBox->addWidget(priorityLabel);

    for (int i = 0; i < countButton; i++)
    {
        QPushButton* priorityButton = new QPushButton(QString::number(i+1), this);
        vBox->addWidget(priorityButton);
    }
}
