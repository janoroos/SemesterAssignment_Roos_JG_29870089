#include "alternwindow.h"
#include "ui_alternwindow.h"

AlternWindow::AlternWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlternWindow)
{
    ui->setupUi(this);
}

AlternWindow::~AlternWindow()
{
    delete ui;
}

void AlternWindow::on_Enter_WF_clicked()
{
    ui->
}
