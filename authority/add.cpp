#include "add.h"
#include "ui_add.h"

#include "qdebug.h"
#include <QSqlQueryModel>
#pragma execution_character_set("utf-8")
add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);


}

add::~add()
{
    delete ui;
}

void add::on_pushButton_2_clicked()
{
    this->close();
}





void add::on_pushButton_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    QString name,password,surface;
    name=ui->LE0->text();
    password=ui->LE2->text();
    switch (ui->comboBox->currentIndex()) {
        case 0:surface="Administrator";
        break;
        case 1:surface="teacher";
        break;
        case 2:surface="student";
        break;
    }
    sql="insert into " +surface + " values ('"+name+"','"+password+"')";
    model->setQuery(sql);
    qDebug()<<sql<<surface;
    this->close();
}

