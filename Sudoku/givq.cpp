#include "givq.h"
#include "ui_givq.h"

#include "truewindow.h"
#include "falsewindow.h"




givQ::givQ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::givQ)
{
    ui->setupUi(this);
    ui->dial->setVisible(false);
    ui->Done->setVisible(false);
    ui->Up->setVisible(false);
    ui->Down->setVisible(false);
    ui->Right->setVisible(false);
    ui->Left->setVisible(false);
    ui->Hint->setVisible(false);
}

givQ::~givQ()
{
    delete ui;
}



QLCDNumber *givQ::set(){
        mylcdn = new QLCDNumber(this);
        mylcdn->setAutoFillBackground(true);
        if(it % 2 == 1){
            p1 = mylcdn->palette();
            p1.setColor(QPalette::Background,QColor (100,100,100,127));
            p1.setColor(QPalette::WindowText,Qt::white);   //變更前景色
            mylcdn->setPalette(p1);    //設定顏色
        }
        mylcdn->setDigitCount(1);         //設定位數
        mylcdn->display(0);
        mylcdn->setGeometry(Qx,Qy,30,30); //設定位置大小
        Qx += 30;
        jt++;
        if(jt % 3 == 0){
            if(jt % 9 == 0){

                it++;
                jt = 0;
                Qy = 90*(it / 3);



            }
            else{
                Qy += 30;
            }
            Qx = 90*(it % 3);

        }


        return mylcdn;
}

QLCDNumber **givQ::settoarray(){
    int i = 0;
    int j = 0;
    for(i = 0;i < 9;i ++){
        for(j = 0;j < 9;j ++){
            mylcd[i][j] = set();
            mylcd[i][j]->show();
        }
    }
        return *mylcd;

}

void givQ::on_dial_valueChanged(int value)
{
    int Qpy = 0;
    for(int i = 0;i < 9;i ++){
        if(y == position[i])
            Qpy = i;
    }
    setPale(x,y,Qpy);
    if(Qprint[Qpy][x] == 0){
        mylcd[y][x]->display(value);
    }
    r[Qpy].at(x) = value;

}



//change color when chosen grid's position changed
void givQ::setPale(int x,int y,int Qpy){
    if(x == lastx && y == lasty)
        return;

    else{

        //if the number can't change, be red
        if(Qprint[Qpy][x] != 0){
            p3 = mylcd[y][x]->palette();
            p3.setColor(QPalette::WindowText,Qt::red);
            mylcd[y][x]->setPalette(p3);
        }
        else{
            mylcd[y][x]->setPalette(Qt::black);
        }
        //change last color to default
        if(lastx != -1 && lasty != -1){
            if(lasty % 2 == 0){
                mylcd[lasty][lastx]->setPalette(mylcd[lasty][lastx]->style()->standardPalette());
            }
            else{
                mylcd[lasty][lastx]->setPalette(p1);
            }
        }
        lastx = x;
        lasty = y;
    }

}


void givQ::on_start_clicked()
{
    ui->start->setVisible(false);
    ui->dial->setVisible(true);
    ui->Done->setVisible(true);
    ui->Up->setVisible(true);
    ui->Down->setVisible(true);
    ui->Right->setVisible(true);
    ui->Left->setVisible(true);
    ui->Hint->setVisible(true);
    settoarray();
    Rand();
    completesudoku();
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
            r[i].push_back(0);
        }
    }
}

void givQ::on_Up_clicked()
{
    x -= 3;
    //if(Qprint)
    if(x < 0){
        x += 9;
        y -= 3;
        if(y < 0)
            y += 9;
    }
}

void givQ::on_Down_clicked()
{
    x += 3;
    if(x > 8){
        x -= 9;
        y += 3;
        if(y > 8)
            y -= 9;

    }

}

void givQ::on_Right_clicked()
{
    x += 1;
    //if(Qprint)
    if((x/3) != ((x - 1)/3)){
        x -= 3;
        y += 1;
        if((y/3) != ((y - 1)/3))
            y -= 3;
    }
}

void givQ::on_Left_clicked()
{

    x -= 1;
    if(x < 0){
        x += 3;
        y -= 1;
        if(y < 0)
            y += 3;
    }
    else if((x/3) != ((x + 1)/3)){
        x += 3;
        y -= 1;
        if((y/3) != ((y + 1)/3))
            y += 3;
    }

}

void givQ::on_Done_clicked()
{
    ui->Done->setVisible(false);
    ui->dial->setVisible(false);
    ui->Up->setVisible(false);
    ui->Down->setVisible(false);
    ui->Right->setVisible(false);
    ui->Left->setVisible(false);
    ui->Hint->setVisible(false);
    check();
}




int *givQ::Rand(){
    srand(time(NULL));
    int zero = rand() % 9;
    int one = rand()% 2+1;
    int three = rand()% 2+1 ;
    int div = zero/3;
    int mod = zero%3;
    position[0] = zero;
    position[1] = position[0]+one;
    position[3] = position[0]+3*three;
    if((position[1] / 3)!= div)
        position[1] -= 3;
    if(position[3] > 8)
        position[3] -= 9;
    for(int i = 0;i < 3;i ++){
        if(i != mod && i != position[1]%3)
            position[2] = 3*div + i;
        if(i != div && i != position[3]/3)
            position[6] = mod + 3*i;
    }
    position[4] = position[1] % 3 + 3*(position[3] / 3);
    position[5] = position[2] % 3 + 3*(position[3] / 3);
    position[7] = position[1] % 3 + 3*(position[6] / 3);
    position[8] = position[2] % 3 + 3*(position[6] / 3);
    return position;
}

void givQ::completesudoku(){
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
                mylcd[position[i]][j]->display(Qprint[i][j]);
            }
    }
}

void givQ::check(){
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
            if(Qprint[i][j] != 0)
                r[i].at(j) = 0;
            else{
                if(r[i].at(j) != Q[i][j]){
                    falsewindow =  new Falsewindow(this);
                    falsewindow->show();
                    return;
                }
            }
        }
    }

    truewin =  new Truewindow(this);
    truewin->show();
}



void givQ::on_Hint_clicked()
{
    int hint = 0;
    ++hint;
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
            if(Qprint[i][j] != 0){
                r[i].at(j) = 0;
            }
            else{
                if( hintnozero == 56 ){
                    ui->Hint->setVisible(false);
                    return;
                }
                else{
                    if(r[i].at(j) == 0){
                        r[i].at(j) = Q[i][j];
                        p2 = mylcd[position[i]][j]->palette();
                        p2.setColor(QPalette::WindowText,QColor(4,255,255,127));
                        mylcd[position[i]][j]->setPalette(p2);
                        mylcd[position[i]][j]->display(r[i][j]);
                        hintnozero ++;
                        return;
                    }
                }
            }

        }
    }

}
