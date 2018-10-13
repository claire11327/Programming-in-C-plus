#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <iostream>

#include "character.h"

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    MyCharacter* PointCharacter;
    char   Spselect;
    double xlarge;
    double ylarge;

public slots:
    void fly();
    void Efly();
    void Deleteb();
    void CheckHP();
private :

};

#endif // BULLET_H
