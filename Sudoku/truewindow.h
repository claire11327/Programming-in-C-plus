#ifndef TRUEWINDOW_H
#define TRUEWINDOW_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class Truewindow;
}

class Truewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Truewindow(QWidget *parent = 0);
    ~Truewindow();

private:
    Ui::Truewindow *ui;
    QLabel *label1;
};

#endif // TRUEWINDOW_H
