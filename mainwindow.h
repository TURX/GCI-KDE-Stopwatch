#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mythread.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MyThread *mThread;

private:
    Ui::MainWindow *ui;

public slots:
    void onNumberChanged(int);

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
};

#endif // MAINWINDOW_H
