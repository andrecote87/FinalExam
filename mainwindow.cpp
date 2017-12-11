#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <math.h>
#include <complex>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    validator = new QDoubleValidator(-1e9,1e9,4,NULL);
    ui->inputlineeditA->setValidator(validator);
    ui->inputlineeditB->setValidator(validator);
    ui->inputlineeditC->setValidator(validator);

    //poly = new Polynomial();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete validator;
}


void MainWindow::calculatebuttonClicked()
{

    //Coefficients that will be inputed
    QString text1 = ui->inputlineeditA->text();
    double A = text1.toDouble();

    QString text2 = ui->inputlineeditB->text();
    double B = text2.toDouble();

    QString text3 = ui->inputlineeditC->text();
    double C = text3.toDouble();

    //Calculation of Roots
    float D = B*B;
    float M = 4 * A * C;
    float N = D-M;
    float x = sqrt(N);
    float y = B*0.5 + x*0.5;
    float z = B*0.5 - x*0.5;


if(D<M) //if the root is imaginary
{
     float N = M-D;
     QString answer1("x  =  %1");
     QString answer2("+  i%1");
      QString answer3("-  i%1");
     float X = sqrt(N);
     float Y = B*0.5 + X*0.5;
     float Z = B*0.5 - X*0.5;

     ui->answerlabel1_2->setText(answer1.arg(B*0.5/A));
     ui->answerlabel1->setText(answer2.arg(X*0.5/A));
     ui->answerlabel2_2->setText(answer1.arg(B*0.5/A));
     ui->answerlabel2->setText(answer3.arg(X*0.5/A));


}
else //if the root is real
{
    QString answer1("x=");
    QString answer2("%1");

     ui->answerlabel1_2->setText(answer1);
     ui->answerlabel2_2->setText(answer1);
     ui->answerlabel1->setText(answer2.arg(y*0.5/A));
     ui->answerlabel2->setText(answer2.arg(z*0.5/A));
}
}
