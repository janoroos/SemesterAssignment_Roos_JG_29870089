#include "dialoganswers.h"
#include "ui_dialoganswers.h"
#include <iostream>
#include <vector>
#include <QLocale>
#include <QDebug>

using namespace std;

vector <double> answerList;
int countt = 0;

DialogAnswers::DialogAnswers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAnswers)
{
    //ui->Constraint->setText(QString::number(1));
    ui->setupUi(this);
}

DialogAnswers::~DialogAnswers()
{
    delete ui;
}

void DialogAnswers::on_Close_clicked()
{
    qDebug()<<answerList;
    this->close();
}



void DialogAnswers::on_Ok_clicked()
{
    ui->Constraint->setText(ui->SB_A->text());

    double M;

    QString DisplayVal = ui->Constraint->text();
    QLocale locale(QLocale::Catalan);
    int z = countt+2;
    QString tag = "Enter answer for constraint " + QString::number(z);
    ui->label_3->setText(tag);

    M = locale.toDouble(DisplayVal);

    answerList.push_back(M);
    countt++;
}
vector <double> DialogAnswers::afvoer3()
{
    return answerList;
}
