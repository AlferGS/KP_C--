#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QDialog>
#include <QButtonGroup>
#include <QGridLayout>

#include "Buttons.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class Battlefield;
}

class Battlefield : public QDialog
{
    Q_OBJECT

public:
    explicit Battlefield(QWidget *parent = nullptr);
    ~Battlefield();
    short int Bwidth, Bheight, Bbombs;
    int **field;

    Ui::Battlefield *battle_ui;
    Battlefield *battle;

public slots:
    void on_exitButton_clicked();

    void create_intern_field();

    void create_visible_field();

private slots:
    void on_NewGameButton_clicked();

};

#endif // BATTLEFIELD_H
