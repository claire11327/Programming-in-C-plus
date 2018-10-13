#include "bullet.h"


bullet::bullet()
{

}

void bullet::fly()
{
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::Deleteb()
{
    this->scene()->removeItem(this);
    delete this;

}

void bullet::Efly()
{
    setPos(x(), y() + 3);
    if(y() > 800) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::CheckHP(){
    int r;
    if (this->PointCharacter->HPstatus == 0){
        if(this->PointCharacter->Charaterdata == '0'){
            r = 25;
        }
        else
            r = 50;
        xlarge = this->PointCharacter->x() - this->x();
        ylarge = this->PointCharacter->y() - this->y();
        if ( xlarge < r && ylarge < r &&  xlarge > (-1)*r && ylarge > (-1)*r){
            std::cout<<this->PointCharacter->Charaterdata<<"\n";
            if(this->Spselect == '1'){
                this->PointCharacter->HPChange(10);
                std::cout<<"lighten\n";
            }
            else{
                this->PointCharacter->HPChange(1);
            }
            this->Deleteb();
        }
    }

    return;

}

