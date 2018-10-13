#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custom.h"
#include "givq.h"
#include "truewindow.h"
#include "falsewindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Custom_clicked()
{
    custom = new Custom(this);
    custom->show();

}

void MainWindow::on_givQ_clicked()
{
    givq= new givQ(this);
    givq->show();
}
