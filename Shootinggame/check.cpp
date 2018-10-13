#include "check.h"

Check::Check()
{

}

void Check::CheckHP(bullet& b,MyCharacter& c){
    if ( b.x() == c.x() && b.y() == c.y()){
        b.Deleteb();
        c.HPChange(0);
    }
    return;

}
