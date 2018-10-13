#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLCDNumber>
#include <QProgressBar>
#include <QTimer>
#include <cstdlib>
#include <iostream>
#include <QBrush>
#include <QDialog>
#include <QMovie>
#include <QImage>
#include <QLabel>
#include <QFont>


#include "bullet.h"
#include "character.h"
#include "check.h"


#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void PSetup();
    void ESetup();
    void BSetup(MyCharacter* P,int i);
    void BESetup();
    void TimeStop();
    void ShowScoreHP();
    void ShowScoreHPSet();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MyCharacter    *player;
    MyCharacter    *enemy;
    QLabel         *label;
    QLabel         *label2;
    QMovie         *movie;
    QLCDNumber     *mylcd;
    QProgressBar   *playerProgressBar;
    QProgressBar   *enemyProgressBar;
    QTimer         *timer;
    QTimer         *etimer;                        //Check Enemy Status ,Attack Enemy Timer
    QTimer         *btimer;
    QImage         img1;
    QImage         img2;

    int            Special;
    char           stopMandK;
    char           an;
    char           pauserestart;
    //int            HPenemy = 10;
    //int            HPplayer = 10;
};

#endif // MAINWINDOW_H














