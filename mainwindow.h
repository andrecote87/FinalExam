#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Polynomial* Poly;
     QDoubleValidator* validator;

public slots:

    void calculatebuttonClicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
