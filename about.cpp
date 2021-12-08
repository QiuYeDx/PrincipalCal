#include "about.h"

about::about(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("简单复数计算器 - 说明");
    this->setFixedSize(480, 240);

    label = new QLabel(this);
    label->setGeometry(10, 0, 470, 240);
    label->setText("复数计算器使用说明:\n"
    "输入一个复数 -> 输入符号(+,-,*,/) -> 输入第二个复数 -> 显示结果 -> q退出\n"
    "                                       ↑                                                        ↓\n"
    "                                       ↑                                                        ↓\n"
    "                                         ←    ←    ←    ←   ←    ←   ←   ←   ←\n"
    "                                             (以  当  前  结  果  为  基  础)\n"
"开发人员:\n"
"         计2006白子涵\n"
"         计2006付修远\n"
"         计2006胡桂源");

}

//实现槽函数
void about::showAbout(){
    this->show();
}
