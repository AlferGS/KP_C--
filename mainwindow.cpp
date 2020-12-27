#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "battlefield.h"
#include "ui_battlefield.h"

#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , main_ui(new Ui::MainWindow)
{
    main_ui->setupUi(this);
    main_ui->Width_lcdNumber->display(Mwidth);
    main_ui->Height_lcdNumber->display(Mheight);
    main_ui->Bombs_lcdNumber->display(Mbombs);
}

MainWindow::~MainWindow()
{
    delete main_ui;
}


void MainWindow::on_OptionsButton_clicked()
{
    options option;
    option.setModal(true);
    option.exec();

    Mwidth = option.getWidth();
    Mheight = option.getHeight();
    Mbombs = option.getBomb();
    main_ui->Width_lcdNumber->display(Mwidth);
    main_ui->Height_lcdNumber->display(Mheight);
    main_ui->Bombs_lcdNumber->display(Mbombs);
}

void MainWindow::on_StartButton_clicked()
{
    if (Mwidth == 0 || Mheight == 0 || Mbombs == 0)
    {
        QMessageBox::critical(this, "Error", "Какой-то из параметров был введён \nнекорректно или равен 0 ");
    }  else  {
    qDebug() << "перед get'ами ";
    qDebug()<< "Mwidth = " + QString::number(Mwidth);
    qDebug()<< "Mheight = " + QString::number(Mheight);
    qDebug()<< " Mbombs = " + QString::number(Mbombs);
    Battlefield field;

    field.Bwidth = getMwidth();
    field.Bheight= getMheight();
    field.Bbombs = getMbombs();

    qDebug()<<"Bwidth = "+QString::number(field.Bwidth);
    qDebug()<<"Bheight = "+QString::number(field.Bheight);
    qDebug()<<"Bbombs = "+QString::number(field.Bbombs);

    qDebug()<<"Создаём математическое поле";
    field.create_intern_field();
    qDebug() << "Создаём визуальное поле";
    field.create_visible_field();
    qDebug() << "Выводим всё на экран";
    qDebug()<<"setupUi выполнен";

    connect(field.battle_ui->NewGameButton, SIGNAL(clicked()), main_ui->StartButton, SLOT(click()));

    field.setModal(true);
    field.exec();
    }
}



void MainWindow::on_Difficult_1_clicked()
{
    setMwidth(7);
    setMheight(5);
    setMbombs(7);
    main_ui->Width_lcdNumber->display(QString::number(Mwidth));
    main_ui->Height_lcdNumber->display(QString::number(Mheight));
    main_ui->Bombs_lcdNumber->display(QString::number(Mbombs));
}

void MainWindow::on_Difficult_2_clicked()
{
    setMwidth(14);
    setMheight(8);
    setMbombs(30);
    main_ui->Width_lcdNumber->display(QString::number(Mwidth));
    main_ui->Height_lcdNumber->display(QString::number(Mheight));
    main_ui->Bombs_lcdNumber->display(QString::number(Mbombs));
}

void MainWindow::on_Difficult_3_clicked()
{
    setMwidth(20);
    setMheight(12);
    setMbombs(72);
    main_ui->Width_lcdNumber->display(QString::number(Mwidth));
    main_ui->Height_lcdNumber->display(QString::number(Mheight));
    main_ui->Bombs_lcdNumber->display(QString::number(Mbombs));
}
