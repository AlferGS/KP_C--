#include "battlefield.h"
#include "ui_battlefield.h"
#include "Buttons.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QDebug>
#include <iostream>
#include <QTime>
#include <QGridLayout>
#include<QMouseEvent>


using namespace std;

Battlefield::Battlefield(QWidget *parent) :
    QDialog(parent),
    battle_ui(new Ui::Battlefield)
{

    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    battle_ui->setupUi(this);
    battle_ui->OpenButton->click();
    QGridLayout *layout;
    battle_ui->Bomb_lcdNumber->display(Bbombs);
}

Battlefield::~Battlefield()
{
    delete battle_ui;
}

void Battlefield::on_exitButton_clicked()
{
    delete layout();
    close();
}

void Battlefield::create_intern_field()
{
    qDebug()<<"начинаем функцию cif";
    qDebug()<<"Bwidth = " + QString::number(Bwidth);
    qDebug()<<"Bheight = " + QString::number(Bheight);
    qDebug()<<"Bbombs = " + QString::number(Bbombs);
    battle_ui->Bomb_lcdNumber->display(Bbombs);

                            // Инициализация переменных
    int **num_field;
    num_field = new int *[Bwidth];

    for(int i= 0; i< Bwidth ; i++)               // cоздание матрицы (выделение памяти)
    {
        num_field[i] = new int [Bheight];
    }
    qDebug () << "Выделили память под матрицу";
                            //заполнение матрицы нулями
    for(int i = 0; i < Bheight ; i++)
    {
        for(int j = 0; j < Bwidth; j++)
        {
            num_field[i][j] = 0;
        }
    }
    qDebug()<<"Заполнили матрицу нулями";
                            //Растановка бомб на поле (9 ~ бомба)

    int flg = 0, i, j;
    qDebug() << "Рандомно раставляем бомбы";
    while (flg < Bbombs)
    {

        j = qrand() % ((Bwidth ) + 0);
        i = qrand() % ((Bheight ) + 0);

        if (num_field[i][j] == 9)
        {
            qDebug() << "Значение уже равно 9";
            continue;
        } else {
            qDebug() << "Координаты новой бомбы i[" << i << "]  j[" << j << "]";
            num_field[i][j] = 9;
            flg ++;
        }
        qDebug() << "flg = " << flg;
    }
    qDebug()<<"Бомбы расставлены \nРастановка остальных чисел";

                                    //Проверка на бомбы в радиусе
    for (int i = 0; i< Bheight; i++)
    {
        for (int j = 0; j< Bwidth; j++)
        {


            if (num_field[i][j] == 9)
            {


                for(int tempI = i-1; tempI< i+2; tempI++)
                {
                    for( int tempJ = j-1; tempJ< j+2; tempJ++)
                    {


                        if(tempI< 0 || tempI> Bheight-1)
                            continue;

                        if(tempJ<0 || tempJ>Bwidth-1)
                            continue;

                        if (num_field[tempI][tempJ] == 9)
                            continue;

                        else
                            num_field[tempI][tempJ]++;
                    }
                }


            }


        }
    }
    qDebug()<<"Числа расставлены";
    qDebug()<<"Результат\n\n";
                                    //Проверочный вывод в console
    for (i = 0; i < Bheight; i++)
    {
        qDebug() << "\n";
        for (int j = 0; j < Bwidth; j++)
        {
            qDebug() << " " << num_field[i][j] << " ";
        }
    }
    qDebug()<<"\nВывод закончен\n";
    field=num_field;
}


void Battlefield::create_visible_field()
{
    qDebug() << " Начало функции cvf";
   // if(layout){
    QGridLayout *layout = new QGridLayout(this);//}
    int pos = 0;
    qDebug() << "Создание указателя на компановщик";

    for (int i = 0; i < Bheight; i++)
    {
        for(int j = 0; j < Bwidth; j++)
        {
            Buttons *button = new Buttons(this);  // Создаем объект динамической кнопки
            //Pbutton = button;
            qDebug()<<"Кнопка создана";
            button->setRow(i);
            button->setCol(j);
            button->setRep(field[i][j]);
            button->setFixedSize(25,25);
            qDebug()<<"Размеры установлены";
            layout->addWidget(button, i, j,Bheight*1.2   ,Bwidth*0.5); //630-Bheight*25 , 1070-Bwidth*25);   //Bheight*1.2   Bwidth*0.5
            pos++;
            qDebug()<<"Кнопка помещена в компановщик";

            connect(button, SIGNAL(clicked()),button, SLOT(slotClick()));

            qDebug()<<"Сигнал подключен к кнопке";
        }
    }
    setLayout(layout);
    qDebug()<<"setLayout выполнен";
}

    // 9 - bomb  0-8 - numbs


void Battlefield::on_NewGameButton_clicked()
{
    battle_ui->exitButton->click();
}
