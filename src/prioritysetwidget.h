#pragma once

#include <QWidget>
#include <QMap>

class QPushButton;

class PrioritySetWidget: public QWidget
{
    Q_OBJECT
public:
    PrioritySetWidget(QWidget* parent = nullptr);

signals:
    void priorityChangeRequested(int);

private slots:
    void sendPriority();

private:
    QMap<QPushButton*,int> priorityMap;
};
