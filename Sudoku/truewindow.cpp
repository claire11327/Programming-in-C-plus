#include "truewindow.h"
#include "ui_truewindow.h"

Truewindow::Truewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Truewindow)
{
    ui->setupUi(this);
    label1 = new QLabel(this);
    label1->setText(tr("Win"));
    label1->setStyleSheet("font : 20pt");
    label1->setGeometry(20,20,100,100);        //設定位置大小
    label1->setAlignment(Qt::AlignCenter);   //label文字置中
}

Truewindow::~Truewindow()
{
    delete ui;
}
