#ifndef CUSTOM_H
#define CUSTOM_H

#include "truewindow.h"
#include "falsewindow.h"

#include <QDialog>
#include <QWidget>
#include <QLCDNumber>
#include <iostream>
#include <vector>
#include <algorithm>

namespace Ui {
class Custom;
}

class Custom : public QDialog
{
    Q_OBJECT

public:
    explicit Custom(QWidget *parent = 0);
    ~Custom();
    //pattern
    QLCDNumber *set();//    creat Qlcd
    QLCDNumber **settoarray();//    Qlcd[9][9] = new Qlcd
    QLCDNumber *mylcdn;
    QLCDNumber *mylcd[9][9];
//first section
    //develop lack()
    void dvplack();
    //get lack by column
    void getlack();
    void getlackpart(int cx,int cy);
    //check
    bool check(int x,int y,int i);
    //void check();
    bool checktrue();
    bool isCorrectR(int cx,int cy,int i);
    bool isCorrectG(int cx, int cy, int t);
    bool sol();
    void Try(int tx,int ty,int i);
    int findfirstzero();
    void PrintA();
    void setPale(int x,int y);

private slots:
    void on_dial_valueChanged(int value);

    
    void on_start_clicked();// start the game

    void on_Up_clicked();

    void on_Down_clicked();

    void on_Right_clicked();

    void on_Left_clicked();

    void on_Done_clicked();
    // set the suduko Question, call fuction to solve the game,  show the answer.
    //(remember to hide it after one click)
    //still need a button to close the window.

private:
    Ui::Custom *ui;
    QPalette p1;
    int x = 0,y = 0;//      the location to give r[9].at(9)value
    int Qx = 0;//           Qlcd location
    int Qy = 0;//           Qlcd location
    int startturn = 0;
    int doneturn = 0;
    int cx;//    check x
    int cy;//    check y
    int ok = 0;
    int lastx = -1;
    int lasty = -1;
    std::vector <int>  r[9];//= {{8,0,0,0,0,0,0,0,1},{9,0,0,0,2,0,0,0,3},{0,3,0,0,5,0,0,7,0},{0,0,5,0,0,0,4,0,0},{0,0,4,5,0,9,6,0,0},{0,0,0,8,0,1,0,0,0},{0,0,0,0,0,0,0,0,0},{0,4,6,0,0,0,8,2,0},{0,2,0,3,0,5,0,9,0}};
//    get the Question
    std::vector <int>  lack[9];
    std::vector <int>  rlack;
    int checktru[9] = {0};
    int tk;
    //int zerox;
    //int zeroy;
    int xy;
    bool re = true;


    Truewindow *truewin;
    Falsewindow *falsewindow;
};

#endif // CUSTOM_H
