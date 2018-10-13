#include "falsewindow.h"
#include "ui_falsewindow.h"

Falsewindow::Falsewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Falsewindow)
{
    ui->setupUi(this);
    label1 = new QLabel(this);
    label1->setText(tr("Fail"));
    label1->setStyleSheet("font : 20pt");
    label1->setGeometry(20,20,100,100);        //設定位置大小
    label1->setAlignment(Qt::AlignCenter);   //label文字置中


}

Falsewindow::~Falsewindow()
{
    delete ui;
}
