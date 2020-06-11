#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "simplexinfo.h"
#include "dialogwindow.h"
#include "matrix.h"
#include "simplexinfo.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Variables->setText(QString::number(1));
    ui->Constraints->setText(QString::number(1));
    connect(ui->Enter, SIGNAL(click()),this,SLOT(openNew_window()));

    DialogWindow A;

    SimplexInfo one;

    /*Matrix <double> C_N(1,one.columns);

    for (int i =0; i < 1;i++)
    {
        for (int j =0;j < one.columns; j++)
        {
            int m = A.Weight();
            C_N.put(i,j,m);
        }
    }*/

}

MainWindow::~MainWindow()
{    
    delete ui;
}


int MainWindow::Waardes()
{
    QString displayVal2 = ui-> Variables -> text();
    int n = displayVal2.toInt();
    return n;
}
int MainWindow::WaardesC()
{
    QString displayVal2 = ui-> Constraints -> text();
    int n = displayVal2.toInt();
    return n;
}

void MainWindow::on_Enter_clicked()
{   
    ui->Constraints->setText(ui->SB_C->cleanText());
    ui->Variables->setText(ui->SB_V->cleanText());

    QString displayVal = ui -> Constraints ->text();
    QString displayVal2 = ui-> Variables -> text();

    SimplexInfo object;
    object.rows = displayVal.toInt();
    object.columns = displayVal2.toInt();


    //ui -> Display -> setText()
}

void MainWindow::openNew_window()
{
    dialogwindow = new DialogWindow();
    dialogwindow -> show();
}
void MainWindow::openNew_window2()
{
    dialogCon = new DialogCon();
    dialogCon -> show();
}

void MainWindow::on_Enter_OF_clicked()
{
    DialogWindow object_one;

    openNew_window();
}

void MainWindow::on_Enter_C_clicked()
{
    DialogWindow object_one;

    openNew_window2();
}
