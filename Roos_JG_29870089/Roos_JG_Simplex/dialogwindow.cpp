#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include <iostream>
#include "simplexinfo.h"
#include "mainwindow.h"
#include "matrix.h"

using namespace std;

QString of_Return = "";
int counter = 0;

DialogWindow::DialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWindow)
{
    ui->setupUi(this);
    ui->Variables_->setText(QString::number(1));
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

    //ui ->Variables->setText(ui->SB_V->cleanText());
    ui->Variables_->setText(ui->doubleSpinBox->cleanText());

    QString displayV = ui->Variables_->text();
    vector <double> list_one;

    m = displayV.toInt();
    list_one.push_back(m);

    QString label_name = "";


    label_name = "Weight of x" + QString::number(counter+1) +": ";
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
    this->close();
}
