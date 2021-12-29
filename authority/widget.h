#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "administration.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void  registerd();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);
signals:
    void sendcur(int);

private:
    Ui::Widget *ui;

    int currt;
    administration *admin;
};
#endif // WIDGET_H
