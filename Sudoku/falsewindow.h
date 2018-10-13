#ifndef FALSEWINDOW_H
#define FALSEWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Falsewindow;
}

class Falsewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Falsewindow(QWidget *parent = 0);
    ~Falsewindow();

private:
    Ui::Falsewindow *ui;
    QLabel *label1;
};

#endif // FALSEWINDOW_H
