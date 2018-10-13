#ifndef CHECK_H
#define CHECK_H
#include "bullet.h"
#include "character.h"

class Check: public QObject
{
    Q_OBJECT
public:
    Check();
    void CheckHP(bullet& ,MyCharacter& );
};

#endif // CHECK_H
