#include "administration.h"
#include "ui_administration.h"
#include "widget.h"
#include <qdebug.h>
#include <QSqlQueryModel>
#include <QMessageBox>
administration::administration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administration)
{
    ui->setupUi(this);
    init();



}

administration::~administration()
{
    delete ui;
}
//增
void administration::on_pushButton_clicked()
{
    al.show();
}

void administration::a(int a)
{
    qDebug()<<a;
    ui->stackedWidget->setCurrentIndex(a);
}

void administration::init()
{
    QString sql_stu,sql_stu1,sql_stu2;
    sql_stu="SELECT * FROM Administrator";
    sql_stu1="SELECT * FROM teacher";
    sql_stu2="SELECT * FROM student";
    QSqlQueryModel *modelx=new QSqlQueryModel;
    QSqlQueryModel *modelx1=new QSqlQueryModel;
    QSqlQueryModel *modelx2=new QSqlQueryModel;
    modelx->setQuery(sql_stu);
    ui->tableView->setModel(modelx);

    modelx1->setQuery(sql_stu1);
    ui->tableView_2->setModel(modelx1);

    modelx2->setQuery(sql_stu2);
    ui->tableView_3->setModel(modelx2);

}

void administration::select(int cur)
{
    switch (currentIndex) {
    case 0:cur=ui->tableView->currentIndex().row();
    break;
    case 1:cur=ui->tableView_2->currentIndex().row();
    break;
    case 2:cur=ui->tableView_3->currentIndex().row();
    break;
    }
}

//改
void administration::on_pushButton_2_clicked()
{

}

//删
void administration::on_pushButton_3_clicked()
{
    int curRow=ui->tableView->currentIndex().row(); //选中行
    qDebug()<<curRow;
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,1);//遍历第一行的所有列
    QVariant datatemp = modessl->data(indextemp);
    //delete from mytablename [where条件]
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    QString name,password,surface;
    name=
    password=
    switch (ui->comboBox->currentIndex()) {
        case 0:surface="Administrator";
        break;
        case 1:surface="teacher";
        break;
        case 2:surface="student";
        break;
    }
    sql="delete from " +surface + " where"')";
    model->setQuery(sql);
    qDebug()<<sql<<surface;
    this->close();
}

//停
void administration::on_pushButton_4_clicked()
{

}

//修
void administration::on_pushButton_5_clicked()
{

}

//增课
void administration::on_pushButton_6_clicked()
{

}

//改课
void administration::on_pushButton_7_clicked()
{

}

//删课
void administration::on_pushButton_8_clicked()
{

}

//改密
void administration::on_pushButton_10_clicked()
{

}

//加课
void administration::on_pushButton_9_clicked()
{

}

//删课
void administration::on_pushButton_11_clicked()
{

}

//改密
void administration::on_pushButton_13_clicked()
{

}


void administration::on_tabWidget_currentChanged(int index)
{
    currentIndex=index;
}

