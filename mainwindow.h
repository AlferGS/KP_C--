#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "options.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow//, public options
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    short int Mwidth = 0, Mheight = 0, Mbombs = 0;
    Ui::MainWindow *main_ui;
    MainWindow *main;

public slots:
    void setMwidth(int width)
    {
        Mwidth = width;
    }

    void setMheight(int height)
    {
        Mheight = height;
    }

    void setMbombs(int bombs)
    {
        Mbombs = bombs;
    }

    int getMwidth()
    {
        return this->Mwidth;
    }

    int getMheight()
    {
        return this->Mheight;
    }

    int getMbombs()
    {
        return this->Mbombs;
    }

private slots:

    void on_OptionsButton_clicked();

    void on_StartButton_clicked();


    void on_Difficult_1_clicked();

    void on_Difficult_2_clicked();

    void on_Difficult_3_clicked();

};
#endif // MAINWINDOW_H
