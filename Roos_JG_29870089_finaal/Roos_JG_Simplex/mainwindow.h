#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialogwindow.h"
#include "dialogcon.h"
#include <QMainWindow>
#include <vector>
#include <iostream>
#include "dialoganswers.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Waardes();
    int WaardesC();
    //void Calculations();
    //vector <double> SimplexRoep();

private slots:
    void on_Enter_clicked();
    void on_Enter_OF_clicked();
    void on_Enter_C_clicked();
    void on_DisplayButton_clicked();
    void on_pushButton_clicked();

    void on_Max_clicked();

    void on_Min_clicked();

public slots:
    void openNew_window();
    void openNew_window2();
    void openNew_window3();

private:
    Ui::MainWindow *ui;
    DialogWindow *dialogwindow; //maak bewus van die ander window..
    DialogCon *dialogCon;
    DialogAnswers *dialogAnswers;
};

#endif // MAINWINDOW_H
