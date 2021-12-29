#include <QCoreApplication>
#include <QDebug>
#include <QSqlRecord>
#include "dataBase.h"
DataBase::DataBase(QString name, QObject *parent)
    : QObject(parent)
{

    if (QSqlDatabase::contains(name)) {

        m_DataBase = QSqlDatabase::database(name);
    }
    else {

        m_DataBase = QSqlDatabase::addDatabase("QSQLITE");
        m_DataBase.setDatabaseName(QCoreApplication::applicationDirPath()+"/"+ name+".db");
    }
    initTable();
}

DataBase::~DataBase()
{
}

bool DataBase::initTable()
{
    if (!m_DataBase.open()) {
        return false;
    }

    if (!isExistTable("students")) {
        createTable("students");
    }
    return false;
}

bool DataBase::isExistTable(QString table)
{
    bool bRet = false;
    if (!m_DataBase.open()) {
        return bRet;
    }
    QSqlQuery query(m_DataBase);
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg(table));    //关键的判断
    if (query.next())
    {
        if (query.value(0).toInt() > 0)
        {
            bRet = true;
        }
    }
    return false;
}

bool DataBase::createTable(QString table)
{
    if (!m_DataBase.open()) {
        return false;
    }

    QSqlQuery query(m_DataBase);
    if (table == QString("students")) {

        bool success = query.exec("CREATE TABLE students ("
                                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "name VARCHAR(40) NOT NULL, "
                                    "score INTEGER NOT NULL, "
                                    "grade VARCHAR(40) NOT NULL)");

        if (success) {
            return true;   //新建数据库成功
        }
        else {
            QSqlError lastError = query.lastError();
            QString err = lastError.driverText();
            return false;
        }
    }
    else {
        return false;
    }
}

bool DataBase::insertData(StudentData data)
{
    if (!m_DataBase.open()) {
        return false;
    }
    QSqlQuery query(m_DataBase);

    bool success = query.exec(QString("INSERT INTO students (name, score,class) "
        "VALUES (%1, %2, %3)").arg(data.name)
                              .arg(data.score)
                              .arg(data.grade));

    if (!success) {

        QSqlError lastError = query.lastError();
        QString err = lastError.driverText();
        return false;
    }
    return true;
}

bool DataBase::deleteData(QString name)
{
    if (!m_DataBase.open()) {
        return false;
    }
    QSqlQuery query(m_DataBase);
    query.prepare(QString("DELETE FROM students WHERE name='%1'").arg(name));
    query.exec();
    return false;
}

bool DataBase::getDataByName(int name, StudentData & data)
{
    if (!m_DataBase.open()) {
        return false;
    }
    QSqlQuery query(m_DataBase);
    query.prepare(QString("SELECT * FROM students WHERE name='%1'").arg(name));
    query.exec();
    QSqlRecord rec = query.record();
    if (query.next())
    {

        data.name = query.value(0).toString();
        data.score = query.value(1).toInt();
        data.grade = query.value(2).toString();

        return true;
    }
    return false;
}

bool DataBase::getDataList(QList<StudentData>& list)
{
    if (!m_DataBase.open()) {
        return false;
    }

    QSqlQuery query(m_DataBase);
    query.prepare(QString("SELECT * FROM students"));
    query.exec();
    QSqlRecord rec = query.record();
    while (query.next())
    {
        StudentData data;
        data.name = query.value(0).toInt();
        data.score = query.value(1).toInt();
        data.grade = query.value(2).toInt();
        list.append(data);
        return true;
    }
    return false;
}

bool DataBase::update()
{
    if (!m_DataBase.open()) {
        return false;
    }

    QSqlQuery query(m_DataBase);
    query.prepare("UPDATE students SET score = 100 , name = '小A'");
    query.exec();
    return false;
}


