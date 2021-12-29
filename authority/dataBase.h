#pragma once

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
struct StudentData{
                   QString name;
                   int score;
                   QString grade;};

class DataBase : public QObject
{
    Q_OBJECT

public:
    DataBase(QString name,QObject *parent=0);
    ~DataBase();
public:
    bool insertData(StudentData data);
    bool deleteData(QString name);
    bool getDataByName(int name, StudentData & data);
    bool getDataList(QList<StudentData> & list);
    bool update();
private:
    QSqlDatabase m_DataBase;
private:
    bool initTable();
    bool isExistTable(QString table);
    bool createTable(QString table);
};
