#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread, SIGNAL(NumberChanged(int)), this, SLOT(onNumberChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumberChanged(int Number) {
    ui->lcdNumberH->display(Number / 3600);
    ui->lcdNumberM->display((Number % 3600) / 60);
    ui->lcdNumberS->display(Number % 60);
}

void MainWindow::on_pushButtonStart_clicked()
{
    mThread->Stop = false;
    mThread->start();
}

void MainWindow::on_pushButtonStop_clicked()
{
    mThread->Stop = true;
    mThread->i = 0;
}
