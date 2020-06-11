#ifndef ALTERNWINDOW_H
#define ALTERNWINDOW_H

#include <QMainWindow>

namespace Ui {
class AlternWindow;
}

class AlternWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlternWindow(QWidget *parent = nullptr);
    ~AlternWindow();

private slots:
    void on_Enter_WF_clicked();

private:
    Ui::AlternWindow *ui;
};

#endif // ALTERNWINDOW_H
