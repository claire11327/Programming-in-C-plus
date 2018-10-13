#include "character.h"
#include <QDebug>

MyCharacter::MyCharacter():
    Specialselect(1),
    Charaterdata(0),
    Specialtime(5),
    HPstatus(0),
    Score(0),
    HP(100)
{
}



bool MyCharacter::HPChange(int i){
    return true;
}



void MyCharacter::Special(){
        HP = 100;
}

void MyCharacter::Test(){

}


void MyCharacter::Move(){
    if(x() >= 1000){
        xp = -10;
    }
    if(x() <= 0){
        xp = 10;
    }
    setPos(x() + xp,y());

}





Player::Player(){

}

void Player::Test(){
    std::cout<<"player\n";
}

bool Player::HPChange(int i){
    HP = HP - i;
    std::cout<<this->Charaterdata<<"HP\n";
    if(HP <= 0){
        std::cout<<"HP\n";
        this->HPstatus = 1;
        return false;
    }
    return true;
}

void Player::Special(){
    if(Specialtime > 0)
        HP = 100;
}











Enemy::Enemy(){

}

void Enemy::Test(){
 std::cout<<"enemy\n";
}




bool Enemy::HPChange(int i){
    HP = HP - i;
    Score = Score + 1;
    std::cout<<HP<<"HP\n";
    if(HP <= 0){
        std::cout<<"HP\n";
        this->HPstatus = 1;
        return false;
        //this->scene()->removeItem(this);
        //delete this;
    }
    return true;
}


void Enemy::Special(){
    srand(time(NULL));
    if(Specialtime > 0 ){
        Specialselect = rand()%2;
        if(Specialselect == 0){
            this->setPixmap(QPixmap(":/res/blackcloud.png").scaled(100,100));
        }
       else{
            this->setPixmap(QPixmap(":/res/cloud.png").scaled(100,80));
            HP = 100;
        }
    }
}





