#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>

class about : public QMainWindow
{
    Q_OBJECT
public:
    explicit about(QWidget *parent = nullptr);
public slots:
    void showAbout(); //声明槽函数
private:
    QLabel *label;
signals:

};

#endif // ABOUT_H
