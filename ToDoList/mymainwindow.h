#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QWidget>

class MyMainWindow : public QWidget
{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
};
#endif // MYMAINWINDOW_H
