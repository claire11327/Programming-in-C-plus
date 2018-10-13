#ifndef GIVQ_H
#define GIVQ_H
#include "truewindow.h"
#include "falsewindow.h"

#include <QDialog>
#include <QLCDNumber>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

namespace Ui {
class givQ;
}

class givQ : public QDialog
{
    Q_OBJECT

public:
    explicit givQ(QWidget *parent = 0);
    ~givQ();
    QLCDNumber *set();//    creat Qlcd
    QLCDNumber **settoarray();//    Qlcd[9][9] = new Qlcd
    void completesudoku();//    creat Qlcd
    int *Rand();
    void check();
    void setPale(int x,int y,int Qpy);

private:
    Ui::givQ *ui;
    QPalette p1,p2,p3;
    QLCDNumber *mylcdn;
    QLCDNumber *mylcd[9][9];
    int x = 0,y = 0;//      the location to give r[9].at(9)value
    int Qx = 0;//           Qlcd location
    int Qy = 0;//           Qlcd location    
    int ix  = 0;
    int iy  = 0;
    int it = 0;
    int jt = 0;
    int lastx = -1;
    int lasty = -1;
    int startturn = 0;
    int doneturn = 0;
    std::vector <int>  r[9];//    get the Question.
    int  Q[9][9] = {{9,6,2,5,7,1,4,8,3},{7,4,5,9,3,8,6,2,1},{8,3,1,6,2,4,9,5,7},{2,3,6,7,1,9,8,4,5},{1,5,9,2,8,4,3,7,6},{7,4,8,3,6,5,2,1,9},{3,5,4,6,2,8,1,9,7},{8,9,2,4,1,7,5,6,3},{1,7,6,5,9,3,4,8,2}};
    int position[9];
    int  Qprint[9][9] = {{9,6,0,0,0,1,0,8,3},{0,4,0,0,0,0,6,0,1},{0,0,0,0,0,4,0,0,0},{0,3,0,7,0,0,0,0,5},{0,0,0,2,0,4,0,0,0},{7,0,0,0,0,5,0,1,0},{0,0,0,6,0,0,0,0,0},{8,0,2,0,0,0,0,6,0},{1,7,0,5,0,0,0,0,2}};
    int hintnozero = 0;

    int zeroposition;
    int oneposition;
    int threeposition;


    Truewindow *truewin;
    Falsewindow *falsewindow;

private slots:
    void on_dial_valueChanged(int value);
    void on_start_clicked();// start the game

    void on_Up_clicked();

    void on_Down_clicked();

    void on_Right_clicked();

    void on_Left_clicked();

    void on_Done_clicked();
    void on_Hint_clicked();
};

#endif // GIVQ_H
