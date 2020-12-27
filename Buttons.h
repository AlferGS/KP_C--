#ifndef BUTTONS_H
#define BUTTONS_H

#include <QMouseEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

#include "battlefield.h"
#include "mainwindow.h"
#include "options.h"
#include "ui_battlefield.h"


class Buttons: public QPushButton
{
    Q_OBJECT

public:
    Buttons(QWidget *parent = nullptr)
    {
        rep = 0;
    };
    ~Buttons()
    {

    }

private:
    short int rep;
    short int col;
    short int row;

public:
    int getRep()
    {
        return this->rep;
    }

    int getCol()
    {
        return this->col;
    }

    int getRow()
    {
        return this->row;
    }

    void setRep(int Repeats)
    {
        rep = Repeats;
    }

    void setCol(int Colums)
    {
        col = Colums;
    }

    void setRow(int Rows)
    {
        row = Rows;
    }


public slots:
    void slotClick()
    {
        if(this->rep == 9)
        {
            Buttons::setText("*");
            QMessageBox::critical(this, "Игра окончена", "Вы подорвались на мине. Начните новую игру, либо выйдите в меню");

        } else {
            Buttons::setText(QString::number(this->rep));
        }
    }
};

#endif // BUTTONS_H
