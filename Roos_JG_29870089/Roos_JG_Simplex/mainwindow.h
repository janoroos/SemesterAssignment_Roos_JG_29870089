#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialogwindow.h"
#include "dialogcon.h"
#include <QMainWindow>

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

private slots:
    void on_Enter_clicked();

    void on_Enter_OF_clicked();

    void on_Enter_C_clicked();

public slots:
    void openNew_window();
    void openNew_window2();

private:
    Ui::MainWindow *ui;
    DialogWindow *dialogwindow; //maak bewus van die ander window..
    DialogCon *dialogCon;
};

#endif // MAINWINDOW_H
