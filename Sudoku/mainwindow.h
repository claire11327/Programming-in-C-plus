#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custom.h"
#include "givq.h"
#include "truewindow.h"
#include "falsewindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Custom_clicked();

    void on_givQ_clicked();

private:
    Ui::MainWindow *ui;
    Custom *custom;
    givQ *givq;
    Truewindow *truewin;
    Falsewindow *falsewindow;
};

#endif // MAINWINDOW_H
