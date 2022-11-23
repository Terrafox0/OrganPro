#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <thread>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QDir>

double num_first;
QString reg_date = "0";
QString reg_mount = "0";
QString reg_year = "0";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->date_1,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_1->setCheckable(true);
    connect(ui->date_2,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_2->setCheckable(true);
    connect(ui->date_3,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_3->setCheckable(true);
    connect(ui->date_4,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_4->setCheckable(true);
    connect(ui->date_5,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_5->setCheckable(true);
    connect(ui->date_6,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_6->setCheckable(true);
    connect(ui->date_7,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_7->setCheckable(true);
    connect(ui->date_8,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_8->setCheckable(true);
    connect(ui->date_9,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_9->setCheckable(true);
    connect(ui->date_10,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_10->setCheckable(true);
    connect(ui->date_11,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_11->setCheckable(true);
    connect(ui->date_12,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_12->setCheckable(true);
    connect(ui->date_13,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_13->setCheckable(true);
    connect(ui->date_14,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_14->setCheckable(true);
    connect(ui->date_15,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_15->setCheckable(true);
    connect(ui->date_16,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_16->setCheckable(true);
    connect(ui->date_17,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_17->setCheckable(true);
    connect(ui->date_18,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_18->setCheckable(true);
    connect(ui->date_19,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_19->setCheckable(true);
    connect(ui->date_20,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_20->setCheckable(true);
    connect(ui->date_21,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_21->setCheckable(true);
    connect(ui->date_22,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_22->setCheckable(true);
    connect(ui->date_23,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_23->setCheckable(true);
    connect(ui->date_24,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_24->setCheckable(true);
    connect(ui->date_25,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_25->setCheckable(true);
    connect(ui->date_26,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_26->setCheckable(true);
    connect(ui->date_27,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_27->setCheckable(true);
    connect(ui->date_28,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_28->setCheckable(true);
    connect(ui->date_29,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_29->setCheckable(true);
    connect(ui->date_30,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_30->setCheckable(true);
    connect(ui->date_31,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_31->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClearDate()
{


          if(reg_date=="1")ui->date_1->setChecked(false);
          if(reg_date=="2")ui->date_2->setChecked(false);
          if(reg_date=="3")ui->date_3->setChecked(false);
          if(reg_date=="4")ui->date_4->setChecked(false);
          if(reg_date=="5")ui->date_5->setChecked(false);
          if(reg_date=="6")ui->date_6->setChecked(false);
          if(reg_date=="7")ui->date_7->setChecked(false);
          if(reg_date=="8")ui->date_8->setChecked(false);
          if(reg_date=="9")ui->date_9->setChecked(false);
          if(reg_date=="10")ui->date_10->setChecked(false);
          if(reg_date=="11")ui->date_11->setChecked(false);
          if(reg_date=="12")ui->date_12->setChecked(false);
          if(reg_date=="13")ui->date_13->setChecked(false);
          if(reg_date=="14")ui->date_14->setChecked(false);
          if(reg_date=="15")ui->date_15->setChecked(false);
          if(reg_date=="16")ui->date_16->setChecked(false);
          if(reg_date=="17")ui->date_17->setChecked(false);
          if(reg_date=="18")ui->date_18->setChecked(false);
          if(reg_date=="19")ui->date_19->setChecked(false);
          if(reg_date=="20")ui->date_20->setChecked(false);
          if(reg_date=="21")ui->date_21->setChecked(false);
          if(reg_date=="22")ui->date_22->setChecked(false);
          if(reg_date=="23")ui->date_23->setChecked(false);
          if(reg_date=="24")ui->date_24->setChecked(false);
          if(reg_date=="25")ui->date_25->setChecked(false);
          if(reg_date=="26")ui->date_26->setChecked(false);
          if(reg_date=="27")ui->date_27->setChecked(false);
          if(reg_date=="28")ui->date_28->setChecked(false);
          if(reg_date=="29")ui->date_29->setChecked(false);
          if(reg_date=="30")ui->date_30->setChecked(false);
          if(reg_date=="31")ui->date_31->setChecked(false);
          //подсвечиваем текущий день
}
void MainWindow::date_select()
{

QDir().mkpath("dates");
ClearDate();
 if (ui->date_1->isChecked())reg_date = "1"; if (ui->date_2->isChecked())reg_date = "2";
 if (ui->date_3->isChecked())reg_date = "3"; if (ui->date_4->isChecked())reg_date = "4";
 if (ui->date_5->isChecked())reg_date = "5"; if (ui->date_6->isChecked())reg_date = "6";
 if (ui->date_7->isChecked())reg_date = "7"; if (ui->date_8->isChecked())reg_date = "8";
 if (ui->date_9->isChecked())reg_date = "9"; if (ui->date_10->isChecked())reg_date = "10";
 if (ui->date_11->isChecked())reg_date = "11"; if (ui->date_12->isChecked())reg_date = "12";
 if (ui->date_13->isChecked())reg_date = "13"; if (ui->date_14->isChecked())reg_date = "14";
 if (ui->date_15->isChecked())reg_date = "15"; if (ui->date_16->isChecked())reg_date = "16";
 if (ui->date_17->isChecked())reg_date = "17"; if (ui->date_18->isChecked())reg_date = "18";
 if (ui->date_19->isChecked())reg_date = "19"; if (ui->date_20->isChecked())reg_date = "20";
 if (ui->date_21->isChecked())reg_date = "21"; if (ui->date_22->isChecked())reg_date = "22";
 if (ui->date_23->isChecked())reg_date = "23"; if (ui->date_24->isChecked())reg_date = "24";
 if (ui->date_25->isChecked())reg_date = "25"; if (ui->date_26->isChecked())reg_date = "26";
 if (ui->date_27->isChecked())reg_date = "27"; if (ui->date_28->isChecked())reg_date = "28";
 if (ui->date_29->isChecked())reg_date = "29"; if (ui->date_30->isChecked())reg_date = "30";
 if (ui->date_31->isChecked())reg_date = "31"; //индексирование дней
     reg_mount = ui->mount->text();
     reg_year = ui->year->text();
     QString fname = "dates/"+ reg_date + reg_mount + reg_year+".txt";
     QFile inputFile(fname); //вывод файла
     inputFile.open(QIODevice::ReadWrite | QIODevice::Text);
     QTextStream in(&inputFile);//перевод текст в line
     QString line = in.readAll();
     inputFile.close();//закрываем файл

     ui->text_read->setText(line);//устанавливаем для чтения
     ui->text_edit->setPlainText(line);//устанавливаем для изменения

     //ClearDate();//подсвечиваем текущий


}

void MainWindow::on_save_button_clicked()
{
    QString fname = "dates/"+ reg_date + reg_mount + reg_year+".txt";
    QFile save_file(fname);
    save_file.open(QIODevice::WriteOnly | QIODevice::Text);
    QString save_text = ui->text_edit->toPlainText();//сохранение измененного текста
    ui->text_read->setText(save_text);
    QTextStream out(&save_file);
    out<<save_text;
    save_file.close();

}


void MainWindow::on_mount_textChanged(const QString &arg1)
{
    if (ui->mount->text()=="1"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="2"){if (ui->year->text().toInt()%4==0)ui->date_29->show();else ui->date_29->hide();
        ui->date_30->hide();ui->date_31->hide();}
    if (ui->mount->text()=="3"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="4"){ui->date_29->show();ui->date_30->show();ui->date_31->hide();}
    if (ui->mount->text()=="5"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="6"){ui->date_29->show();ui->date_30->show();ui->date_31->hide();}
    if (ui->mount->text()=="7"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="8"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="9"){ui->date_29->show();ui->date_30->show();ui->date_31->hide();}
    if (ui->mount->text()=="10"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
    if (ui->mount->text()=="11"){ui->date_29->show();ui->date_30->show();ui->date_31->hide();}
    if (ui->mount->text()=="12"){ui->date_29->show();ui->date_30->show();ui->date_31->show();}
}


void MainWindow::on_year_textChanged(const QString &arg1)
{
    if (ui->mount->text()=="2"){if (ui->year->text().toInt()%4==0)ui->date_29->show();else ui->date_29->hide();
        ui->date_30->hide();ui->date_31->hide();}
}

