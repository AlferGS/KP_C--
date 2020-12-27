#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class options;
}

class options : public QDialog
{
    Q_OBJECT

public:
    explicit options(QWidget *parento = nullptr);
    ~options();
    short int width, height, bombs;

public slots:
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    int getBomb()
    {
        return bombs;
    }


private slots:

    int WidthCheckInt(QString s);
    int HeightCheckInt(QString s);
    int BombCheckInt(QString s);

    void on_saveButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::options *options_ui;
};

#endif // OPTIONS_H
