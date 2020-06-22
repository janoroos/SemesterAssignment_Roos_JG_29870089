#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include <iostream>
#include "simplexinfo.h"
#include "mainwindow.h"
#include "matrix.h"
#include <vector>
#include <QLocale>
#include <QDebug>

using namespace std;

QString of_Return = "";
int counter = 0;
vector <double> list_one;

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);
    ui->Variables_->setText(QString::number(0));
}

DialogWindow::~DialogWindow()
{
    delete ui;
}

void DialogWindow::on_Ok_clicked()
{
    SimplexInfo object_one;

    MainWindow object;
    int variable = object.Waardes();
    double m;

    ui->Variables_->setText(ui->doubleSpinBox->cleanText());

    QString displayV = ui->Variables_->text();
    QLocale locale(QLocale::Catalan);
    m = locale.toDouble(displayV);
    list_one.push_back(m);

    QString label_name = "";

    int z = counter+2;
    label_name = "Weight of x" + QString::number(z) +": ";
    ui->Instruction->setText(label_name);

    /*if(counter == variable)
    {
        ui->Ok->setEnabled(false);
    }*/
    counter++;

}


double DialogWindow::Weight()
{
    QString displayV = ui->Variables_->text();
    double m = displayV.toInt();
    return m;
}


void DialogWindow::on_Close_clicked()
{
    qDebug() << list_one;
    this->close();
}
vector <double> DialogWindow::afvoer1()
{
    return list_one;
}



