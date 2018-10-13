#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <iostream>
#include <QTimer>
#include <cstdlib>
#include <QPixmap>

//#include "bullet.h"


class MyCharacter:public QObject, public QGraphicsPixmapItem,public QPixmap
{
    Q_OBJECT
public:
    MyCharacter();
    int Specialselect;
    int Charaterdata;
    int Specialtime;
    int HPstatus;
    int Score;
    int HP;

public slots:
    void Move();
    virtual void Test();
    virtual bool HPChange(int i);
    virtual void Special();
    //have Special figure to help

protected:
    int xp = 10;
 private:

};


//Player
class Player: public MyCharacter
{
    Q_OBJECT
public:
    Player();
    void Test();
public slots:
    bool HPChange(int i);
    void Special();
    //have Special figure to help

};


//Enemy
class Enemy: public MyCharacter
{
    Q_OBJECT
public:
    Enemy();
    void Test();
    //void Attack();
    //void Attack(int playerx,int playery);

public slots:
    bool HPChange(int i);
    void Special();
    //have Special figure to help

};

#endif // CHARACTER_H

