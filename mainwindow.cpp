#include <iostream>
#include <windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/slika/automehanika.gif");
    ui->label_13->setPixmap(pix.scaled(191,121,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const double PDV=0.17;
    double dijelovi,rSati,satnica,ukupno,rezPDV,UKUPNO,zarada,zarada2;

    dijelovi=ui->lineEdit->text().toDouble();
    rSati=ui->lineEdit_2->text().toDouble();
    satnica=ui->lineEdit_3->text().toDouble();

    ukupno=dijelovi+rSati*satnica;
    ui->lineEdit_4->setText(QString::number(ukupno));

    UKUPNO=(ukupno+ukupno*PDV)-ukupno;
    ui->lineEdit_5->setText(QString::number(UKUPNO));

    rezPDV=ukupno+ukupno*PDV;
    ui->lineEdit_6->setText(QString::number(rezPDV));

    zarada=rSati*satnica;
    ui->label_zarada->setText(QString::number(zarada));

    zarada2=zarada+UKUPNO;
    ui->label_zarada_2->setText(QString::number(zarada2));

    //StandardButton reply=QMessageBox::information(this,"Poruka","Hvala puno i dodite opet",
    //QMessageBox::close());
    //| QMessageBox::No);

   // if(reply == QMessageBox::Yes)
    //{
        //QApplication::closingDown();
    //}
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString::number(0));
    ui->lineEdit_2->setText(QString::number(0));
    ui->lineEdit_3->setText(QString::number(0));
    ui->lineEdit_4->setText(QString::number(0));
    ui->lineEdit_5->setText(QString::number(0));
    ui->lineEdit_6->setText(QString::number(0));
    ui->label_zarada->setText(QString::number(0));
    ui->label_zarada_2->setText(QString::number(0));

    QMessageBox::information(this,"Dovidjenja","Hvala Vam puno i dodjite nam opet");
}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}


/*
 * const double

satnica=2.35,PDV=0.17;

float rSati;
double dijelovi,rez,ukupno;

cout<<"Unesite cijenu dijelova\n";
cin>>dijelovi;
cout<<"Unesite broj radnih sati"<<endl;
cin>>rSati;
ukupno=dijelovi+satnica*rSati;

cout<<"\tAutomehanicarska radnja\n";
cout<<"\tMostar bb\n";
cout<<"___________________________________\n";
cout<<"\tRacun br. 333\n";
cout<<"___________________________________\n";
cout<<"dijelovi..............:  "<<dijelovi<<" KM"<<endl;
cout<<"broj radnih sati......:  "<<rSati<<" KM"<<endl;
cout<<"___________________________________\n";
cout<<"Ukupno bez PDV........:  "<<ukupno<<" KM"<<endl;
rez=ukupno+ukupno*PDV;
ukupno=(ukupno+ukupno*PDV)-ukupno;
cout<<"PDV iznosi............: "<<ukupno<<" KM"<<endl;
cout<<"Cijena s PDV iznosi...: "<<rez<<" KM"<<endl;
cout<<"___________________________________\n";
*/
