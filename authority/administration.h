#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <QWidget>
#include "add.h"
#include <QMenu>
namespace Ui {
class administration;
}

class administration : public QWidget
{
    Q_OBJECT

public:
    explicit administration(QWidget *parent = nullptr);
    ~administration();
    void a(int a);
    void init();
    void select(int cur);
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::administration *ui;
    add al;
    int currentIndex;

};

#endif // ADMINISTRATION_H
