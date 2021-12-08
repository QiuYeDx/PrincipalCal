#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include "about.h"
#include "maincal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;
    QPushButton *btn_about;
    QPushButton *btn_start;
    about *w_about;
    mainCal *w_maincal;
};

#endif // MENU_H
