#include "maincal.h"
#include <QByteArray>
mainCal::mainCal(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("简单复数计算器 - 计算");
    this->setFixedSize(600, 120);

    label_1 = new QLabel(this);
    label_1->setGeometry(15, 20, 120, 20);
    label_1->setText("第一个操作数");

    label_2 = new QLabel(this);
    label_2->setGeometry(165, 20, 120, 20);
    label_2->setText("运算符(+ - * /)");

    label_3 = new QLabel(this);
    label_3->setGeometry(315, 20, 120, 20);
    label_3->setText("第二个操作数");

    label_4 = new QLabel(this);
    label_4->setGeometry(465, 20, 120, 20);
    label_4->setText("运算结果");

    text_1 = new QLineEdit(this);
    text_1->setGeometry(15, 40, 120, 20);

    text_2 = new QLineEdit(this);
    text_2->setGeometry(165, 40, 120, 20);

    text_3 = new QLineEdit(this);
    text_3->setGeometry(315, 40, 120, 20);

    text_4 = new QLineEdit(this);
    text_4->setGeometry(465, 40, 120, 20);

    btn_cal = new QPushButton(this);
    btn_cal->setText("计算");
    btn_cal->setGeometry(180, 70, 100, 40);

    btn_re0 = new QPushButton(this);
    btn_re0->setText("重置");
    btn_re0->setGeometry(320, 70, 100, 40);

    QObject::connect(btn_re0, SIGNAL(clicked()), this, SLOT(Re0()));
    QObject::connect(btn_cal, SIGNAL(clicked()), this, SLOT(check()));
    QObject::connect(btn_cal, SIGNAL(clicked()), this, SLOT(run()));
}

//实现槽函数
void mainCal::showMainCal(){
    this->show();
}

void mainCal::Re0(){
    text_1->clear();
    text_2->clear();
    text_3->clear();
    text_4->clear();
}

void mainCal::check(){
    if(!(text_2->text() == tr("+")|text_2->text() == tr("-")|text_2->text() == tr("*")|text_2->text() == tr("/")) && text_2->text() != "")
        QMessageBox::critical(0 , "非法操作" , "请正确输入运算符!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
    else if(text_2->text() == "/" && text_3->text() == "0")
        QMessageBox::critical(0 , "非法操作" , "除数不能为0!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
    else if(text_1->text() == ""||text_2->text() == ""||text_3->text() == "")
        QMessageBox::critical(0 , "非法操作" , "操作数和运算符不能为空!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
}


nulist* mainCal::InitList_num()
{
    nulist* A =  (nulist*)malloc(sizeof(nulist));
    A->head = (node*)malloc(sizeof(node));
    A->head->next = (node*)malloc(sizeof(node));
    A->head->next->next = NULL;
    return A;
}

void mainCal::run(){
    function fun;
    nulist* A = InitList_num();
    nulist* B = InitList_num();
    char *str[100], *str2[100], s;
    QByteArray ba = text_1->text().toLatin1();
    *str=ba.data();
    QByteArray dc = text_2->text().toLatin1();
    s=dc.data()[0];
    QByteArray cb = text_3->text().toLatin1();
    *str2=cb.data();
    printf("%s %s %c",*str, *str2, s);
    fun.get(A, *str);
    fun.get(B, *str2);
    fun.mode(s,A,B);
    text_4->setText(displayM(*A));
}

QString mainCal::displayM(struct nulist L)
{
    struct node* p=L.head;
    QString ans, x_str, s_str;
    double s,x;
    s=p->num;
    x=p->next->num;
    s_str = QString::number(s, 'f', 3);
    x_str = QString::number(x, 'f', 3);
    ans += s_str;
    if(x>0){
        ans += "+";
        ans += x_str + "i";
    }
    else if(x<0){
        ans += x_str + "i";
    }
    printf("\n%s", ans.toStdString().data());
    return ans;
}
