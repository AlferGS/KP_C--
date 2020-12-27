#include "options.h"
#include "ui_options.h"
#include "mainwindow.h"

using namespace std;

options::options(QWidget *parent) :
    QDialog(parent),
    options_ui(new Ui::options)
{
    options_ui->setupUi(this);
}

options::~options()
{
    delete options_ui;
}


int options::WidthCheckInt(QString x)
{
    int i = 0, n = 0;
    std::string s = x.toLocal8Bit().constData();             //Преобразуем QString в string
        while (s[i]){
            if (int(s[i]) >= 48 && s[i] <= 57){
                n = n * 10 + int(s[i] - 48);
            }
            else
            {
                options_ui->width_line->clear();
                options_ui->error_width_label->clear();
                options_ui->error_width_label->setText("Введите число корректно");
                options_ui->ID_label->setText("False");
            }
            i++;
        }
        if(n < 2 || n > 60)
        {
            options_ui->width_line->clear();
            options_ui->error_width_label->clear();
            options_ui->error_width_label->setText("Введите число в диапазоне от 2 до 60");
            options_ui->ID_label->setText("False");
        }  else {
            options_ui->ID_label->clear();
            options_ui->ID_label->setText("True");
        }
        return n;
}

int options::HeightCheckInt(QString x)
{
    int i = 0, n = 0;
    std::string s = x.toLocal8Bit().constData();            //Преобразуем QString в string
        while (s[i]){
            if (int(s[i]) >= 48 && s[i] <= 57){
                n = n * 10 + int(s[i] - 48);
            }
            else
            {
                options_ui->height_line->clear();
                options_ui->error_height_label->clear();
                options_ui->error_height_label->setText("Введите число корректно");
                options_ui->ID_label->setText("False");
            }
            i++;
        }
        if(n < 2 || n > 30)
        {
            options_ui->height_line->clear();
            options_ui->error_height_label->clear();
            options_ui->error_height_label->setText("Введите число в диапазоне от 2 до 30");
            options_ui->ID_label->setText("False");
        } else {
            options_ui->ID_label->clear();
            options_ui->ID_label->setText("True");
        }
        return n;
}

int options::BombCheckInt(QString x)
{
    int i = 0, n = 0;
    std::string s = x.toLocal8Bit().constData();             //Преобразуем QString в string
        while (s[i]){
            if (int(s[i]) >= 48 && s[i] <= 57){
                n = n * 10 + int(s[i] - 48);
            }
            else
            {
                options_ui->bomb_line->clear();
                options_ui->error_bomb_label->clear();
                options_ui->error_bomb_label->setText("Введите число корректно");
                options_ui->ID_label->setText("False");
            }
            i++;
        }
        if(n < 2 || n > width*height - 1)
        {
            options_ui->bomb_line->clear();
            options_ui->error_bomb_label->clear();
            options_ui->error_bomb_label->setText("Введите число в диапазоне от 2 до "+ QString::number(width*height - 1));
            options_ui->ID_label->setText("False");
       } else {
            options_ui->ID_label->clear();
            options_ui->ID_label->setText("True");
        }
        return n;
}


void options::on_saveButton_clicked()
{
    options_ui->error_width_label->setText("");
    options_ui->error_height_label->setText("");                //Аннулируем все возможные оповещения об ошибках
    options_ui->error_bomb_label->setText("");

    options_ui->ID_label->clear();
    QString Swidth = options_ui->width_line->text();
    QString Sheight = options_ui->height_line->text();           //Принимаем введённые строки
    QString Sbombs = options_ui->bomb_line->text();


    width = WidthCheckInt(Swidth);
    height = HeightCheckInt(Sheight);                       //Проверка введённых данных
    bombs = BombCheckInt(Sbombs);

}


void options::on_exitButton_clicked()
{
    close();
}
