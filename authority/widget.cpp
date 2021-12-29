#include "widget.h"
#include "ui_widget.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <qdebug.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::registerd()
{
    admin =new administration();
    admin->show();
    admin->a(currt);
    qDebug()<<currt;
    this->close();
}



void Widget::on_pushButton_2_clicked()
{

}


void Widget::on_pushButton_clicked()
{
    //admin = *new administration;
    QString sql1,sql2;
    QString sql3;
    QString inputName=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();
    QSqlQueryModel *model1=new QSqlQueryModel;
    QSqlQueryModel *model2=new QSqlQueryModel;
    sql1="select count (*) from student where name='"+inputName+"'";
    model1->setQuery(sql1);
    QModelIndex index1=model1->index(0,0);
    sql2="select password from student where name ='"+inputName+"'";
    model2->setQuery(sql2);
    QModelIndex index2=model2->index(0,0);
    sql1="select count (*) from teacher where name='"+inputName+"'";
    model1->setQuery(sql1);
    QModelIndex index3=model1->index(0,0);
    sql2="select password from teacher where name ='"+inputName+"'";
    model2->setQuery(sql2);
    QModelIndex index4=model2->index(0,0);
    sql1="select count (*) from Administrator where name='"+inputName+"'";
    model1->setQuery(sql1);
    QModelIndex index5=model1->index(0,0);
    sql2="select password from Administrator where name ='"+inputName+"'";
    model2->setQuery(sql2);
    QModelIndex index6=model2->index(0,0);
    if(ui->checkBox_3->isChecked())
    { registerd();
        if(index5.data()!=0&&inputPassword==index6.data())
        {

        }
        else
        {
            QMessageBox::about(NULL,"提示","用户名或密码错误");
        }
    }
    else if(ui->checkBox_2->isChecked()){
        if(index3.data()!=0&&inputPassword==index4.data())
        {
            registerd();
        }
        else
        {
            QMessageBox::about(NULL,"提示","用户名或密码错误");
        }
    }
    else{
        if(index1.data()!=0&&inputPassword==index2.data())
        {
            registerd();
        }
        else
        {
            QMessageBox::about(NULL,"提示","用户名或密码错误");

        }
    }


}


void Widget::on_checkBox_stateChanged(int arg1)
{
    bool status = ui->checkBox->isChecked();
    if(status==true){
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        currt=2;
    }
}


void Widget::on_checkBox_2_stateChanged(int arg1)
{
    bool status = ui->checkBox_2->isChecked();
    if(status==true){
        ui->checkBox->setChecked(false);
        ui->checkBox_3->setChecked(false);
        currt=1;
    }
}


void Widget::on_checkBox_3_stateChanged(int arg1)
{
    bool status = ui->checkBox_3->isChecked();
    if(status==true){
        ui->checkBox_2->setChecked(false);
        ui->checkBox->setChecked(false);
        currt=0;
    }
}

