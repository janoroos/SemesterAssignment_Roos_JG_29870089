#include "dialogcon.h"
#include "ui_dialogcon.h"
#include "mainwindow.h"
#include "matrix.h"
#include "simplexinfo.h"

using namespace std;



DialogCon::DialogCon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCon)
{
    ui->setupUi(this);
}

DialogCon::~DialogCon()
{
    delete ui;
}

void DialogCon::on_Close_clicked()
{
    this->close();
}



void DialogCon::on_Ok_clicked()
{
    SimplexInfo one;
    MainWindow object;
    one.rows = object.Waardes();
    one.columns = object.WaardesC();

    Matrix <double> N(one.rows,one.columns);

    ui-> label_2 -> setText(ui->SB_CC->cleanText() );

    QString displayVal = ui->label_2->text();
    double M = displayVal.toDouble();

    /*N.put(z,y,M);


    if(y == one.columns-1)
    {
        y=0;
        z++;
    }
    else if (z == one.columns)
    {
        this -> close();

    }*/


}
