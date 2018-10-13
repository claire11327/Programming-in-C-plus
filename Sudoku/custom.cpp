#include "custom.h"
#include "ui_custom.h"

#include "truewindow.h"
#include "falsewindow.h"

Custom::Custom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Custom)
{
    ui->setupUi(this);
    ui->dial->setVisible(false);
    ui->Done->setVisible(false);
    ui->Up->setVisible(false);
    ui->Down->setVisible(false);
    ui->Right->setVisible(false);
    ui->Left->setVisible(false);


}

Custom::~Custom()
{
    delete ui;
}



QLCDNumber *Custom::set(){

    int colorx = Qx/30,colory = Qy/30;
        mylcdn = new QLCDNumber(this);
        mylcdn->setAutoFillBackground(true);
        if(colorx < 6 && colorx > 2){
            if(colory < 3 || colory > 5){
                p1 = mylcdn->palette();
                //p1.setColor(QPalette::Window,Qt::yellow);    //變更背景色
                p1.setColor(QPalette::Background,QColor (100,100,100,127));
                p1.setColor(QPalette::WindowText,Qt::white);   //變更前景色
                mylcdn->setPalette(p1);    //設定顏色
            }

        }
        if(colorx < 3 || colorx > 5){
            if(colory < 6 && colory > 2){
                QPalette p1 = mylcdn->palette();
                p1.setColor(QPalette::Background,QColor (100,100,100,127));
                p1.setColor(QPalette::WindowText,Qt::white);   //變更前景色
                mylcdn->setPalette(p1);    //設定顏色
            }


        }

        mylcdn->setDigitCount(1);         //設定位數
        mylcdn->display(0);
        mylcdn->setGeometry(Qx+30,Qy+30,30,30); //設定位置大小
        Qx += 30;
        if(Qx > 240){
            Qx = 0;
            Qy += 30;
        }
        return mylcdn;
};

QLCDNumber **Custom::settoarray(){
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

void Custom::on_dial_valueChanged(int value)
{
    setPale(x,y);
    mylcd[y][x]->show();
    mylcd[y][x]->display(value);
    r[x].at(y) = value;

}


//change color when chosen grid's position changed
void Custom::setPale(int x,int y){
    if(x == lastx && y == lasty)
        return;

    else{
        mylcd[y][x]->setPalette(Qt::black);
        if(lastx != -1 && lasty != -1){
            //change last color to default
            if((lasty / 3 == 1 && lastx / 3 != 1) || (lasty / 3 != 1 && lastx / 3 == 1)){
                mylcd[lasty][lastx]->setPalette(p1);

            }
            else{
                mylcd[lasty][lastx]->setPalette(mylcd[lasty][lastx]->style()->standardPalette());
            }
        }
        lastx = x;
        lasty = y;
    }

}


void Custom::on_start_clicked()
{

    if(startturn == 0){
        settoarray();
        ++startturn;
        ui->start->setVisible(false);
        ui->dial->setVisible(true);
        ui->Done->setVisible(true);
        ui->Up->setVisible(true);
        ui->Down->setVisible(true);
        ui->Right->setVisible(true);
        ui->Left->setVisible(true);
        for(int i = 0;i < 9;i ++){
            for(int j = 0;j < 9;j ++){
                r[i].push_back(0);
            }
        }
    }
}

void Custom::on_Up_clicked()
{
    y--;
    if(y < 0){
        y += 9;
    }
}

void Custom::on_Down_clicked()
{
    y++;
    if(y > 8){
        y -= 9;
    }
}

void Custom::on_Right_clicked()
{
    x++;
    if(x > 8){
        x -= 9;
    }
}

void Custom::on_Left_clicked()
{
    x--;
    if(x < 0){
        x += 9;
    }
}

void Custom::on_Done_clicked()
{
    if(doneturn == 0){
        ++doneturn;
        bool chre;

        chre = checktrue();
        if(chre == false){
            return;
        }

        sol();
        PrintA();
        ui->Done->setVisible(false);
        ui->dial->setVisible(false);
        ui->Up->setVisible(false);
        ui->Down->setVisible(false);
        ui->Right->setVisible(false);
        ui->Left->setVisible(false);
    }
}



bool Custom::checktrue(){
    //check column
    for(int k = 0;k < 9;k ++){
        int arr_unity[9];
        for(int i=0; i<9; ++i)
            arr_unity[i] = 0;    // initialize


        for(int i=0; i<9; ++i){
            if(r[k].at(i)!=0)
                ++arr_unity[r[k].at(i)-1];
        }// count



        for(int i=0; i<9; ++i)
            if(arr_unity[i] > 1)   // all element
                return false;          // must be 1
    }

    //check row

    for(int k = 0;k < 9;k ++){
        int arr_unity[9];
        for(int i=0; i<9; ++i)
            arr_unity[i] = 0;    // initialize
        for(int i=0; i<9; ++i){
            if(r[k].at(i)!=0)
                ++arr_unity[r[i].at(k)-1];
            }// count
        for(int i=0; i<9; ++i)
            if(arr_unity[i] > 1)   // all element
                return false;          // must be 1
    }

    //check cell

    for(int k = 0;k < 9;k ++){
        int arr_unity[9];
        for(int i=0; i<9; ++i)
            arr_unity[i] = 0;    // initialize
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(r[3 * (k % 3) + i].at(3 * (k / 3) + j)!=0)
                    ++arr_unity[r[3 * (k % 3) + i].at(3 * (k / 3) + j)-1];
                }
        }// count
        for(int i=0; i<9; ++i)
            if(arr_unity[i] > 1)   // all element
                return false;          // must be 1
    }

    return true;

}

void Custom::Try(int tx,int ty,int tk){
    r[tx].at(ty) = tk;
}



int Custom::findfirstzero(){
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
            if(r[i].at(j)==0){
                return  10*(i+1)+j;
            }
        }
    }
    return -1;

}


bool Custom::check(int zerox,int zeroy,int i){
    for(int ckcol = 0;ckcol < 9;ckcol ++){
        if(r[zerox].at(ckcol) == i){
            return false;

        }
    }

    //row
    for(int ckrow = 0;ckrow < 9;ckrow ++){
        if(r[ckrow].at(zeroy) == i){
            return false;
        }
    }



    //grid
    for(int ckcellr = 0;ckcellr < 3;ckcellr ++){
        for(int ckcellc = 0;ckcellc < 3;ckcellc ++){
            if(r[3*(zerox/3) + ckcellr].at(3*(zeroy/3)+ckcellc) == i){
                return false;
            }
        }
    }
    return true;

}




bool Custom::sol()
{
    if(findfirstzero()==-1)//end
    {
        if(checktrue() == true)
            return true;
    }
    else {
        xy = findfirstzero();
        int zerox = (xy / 10) - 1;
        int zeroy = xy % 10;
        int i = 1;
        for(i = 1;i < 10;i ++){
            re = check(zerox,zeroy,i);
            if(re == true){
                Try(zerox,zeroy,i);
                if(sol())
                    return true;
                else
                    Try(zerox,zeroy,0);
            }
        }

          //Try(zerox,zeroy,0);
           return false;
    }
    return false;
}



void Custom::PrintA(){
    for(int i = 0;i < 9;i ++){
        for(int j = 0;j < 9;j ++){
            mylcd[j][i]->display(r[i].at(j));

        }
    }
}

