#ifndef DIALOGANSWERS_H
#define DIALOGANSWERS_H
#include <vector>
#include <iostream>
#include <QDialog>

using namespace std;

namespace Ui {
class DialogAnswers;
}

class DialogAnswers : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAnswers(QWidget *parent = nullptr);
    ~DialogAnswers();
    vector <double> afvoer3();

private slots:
    void on_Close_clicked();

    void on_Ok_clicked();

private:
    Ui::DialogAnswers *ui;
};

#endif // DIALOGANSWERS_H
