#include "dialogcon.h"
#include "ui_dialogcon.h"
#include "mainwindow.h"
#include "matrix.h"
#include "simplexinfo.h"
#include <iostream>
#include <vector>
#include <QDebug>
#include <QLocale>
#include <QPixmap>

using namespace std;

vector <double> List;

DialogCon::DialogCon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCon)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/janor/Documents/2020/REII 313 Taak/Picture/Constraints entered");
    ui->Picture_label->setPixmap(pic);
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

    ui->label_2->setText(ui->SB_CC->cleanText());
    QString displayVal = ui->label_2->text();
    QLocale locale(QLocale::Catalan);

    double M = locale.toDouble(displayVal);

    List.push_back(M);

    qDebug() << "M: " << M;
}

vector <double> DialogCon::afvoer()
{
    return List;
}
