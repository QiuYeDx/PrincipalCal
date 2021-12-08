#include "menu.h"
#include "about.h"
#include "maincal.h"
#include "ui_menu.h"
#include <QPushButton>
#include <QLabel>

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    w_about = new about;
    w_maincal = new mainCal;
    //设置菜单界面标题
    this->setWindowTitle("简单复数计算器v1.0");
    //设置菜单界面大小
    this->setFixedSize(300,100);
    //设置背景颜色
    //QPalette palette = this->palette(); //获取调色板
    //palette.setColor(QPalette::Window, QColor(255,255,255)); //设置为白色
    //this->setPalette(palette); //重新设置调色板

    //添加按钮
    btn_start = new QPushButton("开始", this);
    btn_start->setGeometry(40, 40, 100, 40);
    btn_about = new QPushButton("关于", this);
    btn_about->setGeometry(160, 40, 100, 40);

    //添加QLabel控件
    QLabel *label = new QLabel(this);  //创建QLabel控件
    label->setGeometry(90,10,120,30);
    label->setText(tr("「简单复数计算器」"));  //设置控件文本
    label->setAlignment(Qt::AlignCenter);  //文本水平和垂直都居中

    QObject::connect(btn_about,SIGNAL(clicked()),w_about,SLOT(showAbout()));
    QObject::connect(btn_start,SIGNAL(clicked()),w_maincal,SLOT(showMainCal()));
}

menu::~menu()
{
    delete ui;
}

