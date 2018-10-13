#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1201, 871)),
    timer(new QTimer),
    etimer(new QTimer),
    btimer(new QTimer),
    img1(":/res/player.png"),
    img2(":/res/player.png"),
    Special(0),
    stopMandK(0),
    an(0),
    pauserestart(0)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/res/background.jpeg").scaled(1200,900)));
    ui->pushButton_2->hide();
    enemyProgressBar = ui->progressBar;
    playerProgressBar = ui->progressBar_2;
    mylcd = ui->lcdNumber;
    label = ui->label;
    label2 = ui->label_2;
    srand(time(NULL));
    PSetup();
    ESetup();
    ShowScoreHPSet();
    img1 = img1.mirrored(true,false);
    etimer->start(100);
    btimer->start(10);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete etimer;
    delete btimer;
    delete mylcd;
    delete label;
    delete label2;
    delete playerProgressBar;
    delete enemyProgressBar;
}






void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(stopMandK == 0){
        switch(e->key()) {
        case Qt::Key_Up:
        case Qt::Key_W:
            player->setPos(player->x(), player->y() - 10);
            if(player->y()<0)
                player->setPos(player->x(), player->y() + 10);
            break;
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            player->setPos(player->x(), player->y() + 10);
            if(player->y()>1200)
                player->setPos(player->x(),0);
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            player->setPixmap(QPixmap::fromImage(img1).scaled(50,50));
            player->setPos(player->x() - 10, player->y());
            if(player->x()<0)
                player->setPos(1200, player->y());
        break;
        case Qt::Key_Right:
        case Qt::Key_D:
           player->setPixmap(QPixmap::fromImage(img2).scaled(50,50));
           player->setPos(player->x() + 10, player->y());
           if(player->x()>1200)
               player->setPos(0, player->y());
           break;
        case Qt::Key_X:
            player->Special();
            player->Specialtime--;
            enemy->Special();
            enemy->Specialtime--;
            break;
        case Qt::Key_Space:
            if(stopMandK == 0){
                BSetup(player,0);
            }
            break;
        }
    }
    else
        return;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(stopMandK == 0){
        BSetup(player,0);
    }
    else
        return;
}






void MainWindow::PSetup(){
    player = new Player;
    player->Charaterdata = 0;
    player->setPixmap(QPixmap(":/res/player.png").scaled(50,50));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(player));
    player->setPos(100,500);//this  ->player->setup
}




void MainWindow::ESetup(){
    enemy = new Enemy;
    int ran = rand() % 1200;
    enemy->Charaterdata = 1;
    enemy->setPixmap(QPixmap(":/res/cloud.png").scaled(100, 80));
    enemy->setPos(ran, 100);//this  ->enemy->setup
    scene->addItem(static_cast<QGraphicsPixmapItem*>(enemy));//this  ->enemy->setup
    enemy->connect(timer, SIGNAL(timeout()), enemy ,SLOT(Move()));
    enemy->connect(timer, SIGNAL(timeout()), this ,SLOT(ShowScoreHP()));
    enemy->connect(etimer, SIGNAL(timeout()), this ,SLOT(BESetup()));



}

void MainWindow::BESetup(){
    BSetup(enemy,1);
}

void MainWindow::BSetup(MyCharacter *P,int i){

    if(player->HPstatus == 0 && enemy->HPstatus == 0){
        bullet *b = new bullet;

        if(i == 0) {
            b->PointCharacter = enemy;
            b->setPixmap(QPixmap(":/res/fire.png").scaled(50, 50));
            b->setPos(P->x() + P->pixmap().width() / 2 - b->pixmap().width() / 2, P->y() - b->pixmap().height());
            b->connect(btimer, SIGNAL(timeout()), b,  SLOT(fly()));
            b->connect(timer, SIGNAL(timeout()), b, SLOT(CheckHP()));
        }
        else {
            b->PointCharacter = player;
            if(enemy->Specialselect == 0){
                b->setPixmap(QPixmap(":/res/lighten.png").scaled(50, 50));
                b->Spselect = '1';
            }
            if(enemy->Specialselect == 1){
                b->setPixmap(QPixmap(":/res/rain.png").scaled(150, 150));
                b->Spselect = '0';
            }
            b->setPos(P->x() + P->pixmap().width() / 2 - b->pixmap().width() / 2, P->y() + b->pixmap().height());
            b->connect(btimer, SIGNAL(timeout()), b, SLOT(Efly()));
            b->connect(timer, SIGNAL(timeout()), b, SLOT(CheckHP()));
        }
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
    }
    else{
        //add dialog

        //disconnect(timer,0,0,0);
        //this->close();
        //std::cout<<"end\n";
        TimeStop();
        delete enemy;
        delete enemyProgressBar;
        delete player;
        delete playerProgressBar;

    }




}

void MainWindow::TimeStop(){
    etimer->stop();
    timer->stop();
    ui->pushButton->hide();
    stopMandK = '1';
    int ra = rand()%5;
    QFont f("Ariel",20,QFont::Light);

    if(player->HPstatus == 0){
        //you win;
        switch (ra) {
        case 0:
            movie = new QMovie(":/res/100.gif");
            break;
        case 1:
            movie = new QMovie(":/res/wow.gif");
            break;
        case 2:
            movie = new QMovie(":/res/easy.gif");
            break;
        case 3:
            movie = new QMovie(":/res/handsome.gif");
            break;
        case 4:
            movie = new QMovie(":/res/fighting.gif");
            break;
        default:
            break;
        }

        label->setText("You win \nYou get "+QString::number(enemy->Score)+" points");

    }
    else{
        //you lose;
        switch (ra) {
        case 0:
            movie = new QMovie(":/res/cry.gif");
            break;
        case 1:
            movie = new QMovie(":/res/ImWrong.gif");
            break;
        case 2:
            movie = new QMovie(":/res/roll.gif");
            break;
        case 3:
            movie = new QMovie(":/res/Dontleaveme.gif");
            break;
        case 4:
            movie = new QMovie(":/res/over.gif");
            break;
        default:
            break;
        }
        label->setText("You lose \nYou get "+QString::number(enemy->Score)+" points");
    }   
    label2->setGeometry(150,300,500,500);
    movie->setScaledSize(label2->size());
    label2->setMovie(movie);
    movie->start();
    label2->show();

    label->setGeometry(300,50,450,70);
    label->setFont(f);
    label->show();
    ui->pushButton_2->show();
}


void MainWindow::ShowScoreHP(){
    mylcd->display(enemy->Score);
    enemyProgressBar->setGeometry(enemy->x()+enemy->pixmap().width()/2,enemy->y()+enemy->pixmap().height(),118,23);
    enemyProgressBar->setValue(enemy->HP);
    playerProgressBar->setGeometry(player->x()+player->pixmap().width()/2,player->y()+player->pixmap().height(),118,23);
    playerProgressBar->setValue(player->HP);
}

void MainWindow::ShowScoreHPSet(){
    mylcd->setGeometry(1000,500,100,30);
    mylcd->show();
}




void MainWindow::on_pushButton_clicked()
{
    if(pauserestart == '0'){
        etimer->stop();
        timer->stop();
        pauserestart = '1';
        movie = new QMovie(":/res/excuseme.gif");
        label2->setGeometry(150,300,500,500);
        movie->setScaledSize(label2->size());
        label2->setMovie(movie);
        movie->start();
        label2->show();
        ui->pushButton->setText("Restart");
    }
    else{
        label2->hide();
        etimer->start(100);
        timer->start(10);
        pauserestart = '0';
        ui->pushButton->setText("Pause");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
