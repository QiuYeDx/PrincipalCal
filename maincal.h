#ifndef MAINCAL_H
#define MAINCAL_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <function.h>
#include <cstring>
class mainCal : public QMainWindow
{
    Q_OBJECT
public slots:
    void showMainCal(); //声明槽函数
    void Re0();
    void check();
    void run();
private:
    QPushButton *btn_cal;
    QPushButton *btn_re0;
    QLabel *label_1, *label_2, *label_3, *label_4;
    QLineEdit *text_1, *text_2, *text_3, *text_4;

public:
    explicit mainCal(QWidget *parent = nullptr);
    nulist* InitList_num();
    QString displayM(struct nulist L);
signals:

};

#endif // MAINCAL_H
