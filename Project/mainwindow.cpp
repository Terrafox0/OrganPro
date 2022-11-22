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

double num_first;
int reg_date = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plusminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_proc,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_eq,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_pros,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_eq->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_pros->setCheckable(true);

    connect(ui->date_1,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_1->setCheckable(true);
    connect(ui->date_2,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_2->setCheckable(true);
    connect(ui->date_3,SIGNAL(clicked()),this,SLOT(date_select()));
    ui->date_3->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton *) sender();
   double all_numbers;
   QString new_label;
   if((ui->result_show->text().contains("."))&&(button->text()=="0"))
   {
       new_label = ui->result_show->text()+button->text();
   }else{
   all_numbers = (ui->result_show->text() + button->text()).toDouble();
   new_label = QString::number(all_numbers,'g',15);}
   ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text() + ".");

}

void MainWindow::operations()
{
   QPushButton *button = (QPushButton *) sender();

   double all_numbers;
   QString new_label;

   if (button->text()=="+/-")
   {
   all_numbers = (ui->result_show->text()).toDouble();
   all_numbers = all_numbers * -1;
   new_label = QString::number(all_numbers,'g',15);
   }
   if (button->text()=="%")
   {
   all_numbers = (ui->result_show->text()).toDouble();
   all_numbers = all_numbers * 0.01;
   new_label = QString::number(all_numbers,'g',15);
   }
   ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_delete_clicked()
{
ui->pushButton_plus->setChecked(false);
ui->pushButton_minus->setChecked(false);
ui->pushButton_eq->setChecked(false);
ui->pushButton_pros->setChecked(false);
ui->result_show->setText("0");
}

void MainWindow::math_operations()
{
   QPushButton *button = (QPushButton *) sender();
   num_first=ui->result_show->text().toDouble();
   //if(ui->pushButton_plus->isChecked())ui->result_show->setText("+");
   //if(ui->pushButton_minus->isChecked())ui->result_show->setText("-");
   //if(ui->pushButton_pros->isChecked())ui->result_show->setText("*");
   //if(ui->pushButton_eq->isChecked())ui->result_show->setText("/");
   ui->result_show->setText("");
   button->setChecked(true);
}



void MainWindow::on_pushButton_res_clicked()
{
    double label_number, num_second;
    QString new_label;
    num_second=ui->result_show->text().toDouble();
    if(ui->pushButton_plus->isChecked()){

        label_number=num_first+num_second;
        new_label = QString::number(label_number,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()){

        label_number=num_first-num_second;
        new_label = QString::number(label_number,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_eq->isChecked()){
        if (num_second==0){ui->result_show->setText("0");}
        else {
        label_number=num_first/num_second;
        new_label = QString::number(label_number,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_eq->setChecked(false);
        }
    }
    else if(ui->pushButton_pros->isChecked()){

        label_number=num_first*num_second;
        new_label = QString::number(label_number,'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_pros->setChecked(false);
    }
}


void MainWindow::on_pushButton_eq_clicked()
{

}

void MainWindow::date_select()
{

 if (ui->date_1->isChecked())
 {

     reg_date = 1; //сохранение индекса дня

     QFile inputFile("1.txt"); //вывод файла
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);//перевод текст в line
     QString line = in.readAll();
     inputFile.close();//закрываем файл

     ui->text_read->setText(line);//устанавливаем для чтения
     ui->text_edit->setPlainText(line);//устанавливаем для изменения
 }
 if (ui->date_2->isChecked())
 {
     reg_date = 2;
     QFile inputFile("2.txt"); //вывод файла
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);//перевод текст в line
     QString line = in.readAll();
     inputFile.close();//закрываем файл
     ui->text_read->setText(line);//устанавливаем для чтения
     ui->text_edit->setPlainText(line);//устанавливаем для изменения
 }
 if (ui->date_3->isChecked())
 {
     reg_date = 3;
     QFile inputFile("3.txt"); //вывод файла
     inputFile.open(QIODevice::ReadOnly);
     QTextStream in(&inputFile);//перевод текст в line
     QString line = in.readAll();
     inputFile.close();//закрываем файл
     ui->text_read->setText(line);//устанавливаем для чтения
     ui->text_edit->setPlainText(line);//устанавливаем для изменения
 }
 ui->date_3->setChecked(false);ui->date_2->setChecked(false);ui->date_1->setChecked(false);
}

void MainWindow::on_save_button_clicked()
{
    if (reg_date==1){
    QFile save_file("1.txt");
    save_file.open(QIODevice::WriteOnly | QIODevice::Text);
    QString save_text = ui->text_edit->toPlainText();//сохранение измененного текста
    ui->text_read->setText(save_text);
    QTextStream out(&save_file);
    out<<save_text;
    save_file.close();}
    else if (reg_date==2){
        QFile save_file("2.txt");
        save_file.open(QIODevice::WriteOnly | QIODevice::Text);
        QString save_text = ui->text_edit->toPlainText();//сохранение измененного текста
        ui->text_read->setText(save_text);
        QTextStream out(&save_file);
        out<<save_text;
        save_file.close();}
    else if (reg_date==3){
        QFile save_file("3.txt");
        save_file.open(QIODevice::WriteOnly | QIODevice::Text);
        QString save_text = ui->text_edit->toPlainText();//сохранение измененного текста
        ui->text_read->setText(save_text);
        QTextStream out(&save_file);
        out<<save_text;
        save_file.close();}
}

