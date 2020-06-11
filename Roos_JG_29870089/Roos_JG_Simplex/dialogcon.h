#ifndef DIALOGCON_H
#define DIALOGCON_H

#include <QDialog>
#include <vector>
#include <iostream>

using namespace std;


namespace Ui {
class DialogCon;
}

class DialogCon : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCon(QWidget *parent = nullptr);
    ~DialogCon();

private slots:
    void on_Close_clicked();
    void on_Ok_clicked();

private:
    Ui::DialogCon *ui;
};

#endif // DIALOGCON_H
