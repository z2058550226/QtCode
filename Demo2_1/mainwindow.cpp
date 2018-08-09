#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    curve.setAmplitude(1.00);
    curve.setOvershoot(10.00);
    curve.setPeriod(0.50);

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->btn1,"geometry");
    animation1->setDuration(3000);
    animation1->setStartValue(ui->btn1->geometry());
    animation1->setEndValue(QRect(50,200,100,50));
    animation1->setLoopCount(1);
    animation1->setEasingCurve(curve);
    //    animation1->start();

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->btn2,"geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(ui->btn2->geometry());
    animation2->setEndValue(QRect(150,200,100,50));
    animation2->setLoopCount(1);
    animation2->setEasingCurve(curve);
    //    animation2->start();

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->btn3,"geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(ui->btn3->geometry());
    animation3->setEndValue(QRect(250,200,100,50));
    animation3->setEasingCurve(curve);
    //    animation3->start();

    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->btn4,"geometry");
    animation4->setDuration(3000);
    animation4->setStartValue(ui->btn4->geometry());
    animation4->setEndValue(QRect(50,300,100,50));
    animation4->setEasingCurve(curve);

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->btn5,"geometry");
    animation5->setDuration(3000);
    animation5->setStartValue(ui->btn5->geometry());
    animation5->setEndValue(QRect(150,300,100,50));
    animation5->setEasingCurve(curve);

    QPropertyAnimation *animation6 = new QPropertyAnimation(ui->btn6,"geometry");
    animation6->setDuration(3000);
    animation6->setStartValue(ui->btn6->geometry());
    animation6->setEndValue(QRect(250,300,100,50));
    animation6->setEasingCurve(curve);

    //    QParallelAnimationGroup *animGroup = new QParallelAnimationGroup;
    QParallelAnimationGroup *group1 = new QParallelAnimationGroup;
    QParallelAnimationGroup *group2 = new QParallelAnimationGroup;

    QSequentialAnimationGroup *animGroup = new QSequentialAnimationGroup;
    group1->addAnimation(animation1);
    group1->addAnimation(animation2);
    group1->addAnimation(animation3);

    group2->addAnimation(animation4);
    group2->addAnimation(animation5);
    group2->addAnimation(animation6);
    animGroup->addAnimation(group1);
    animGroup->addAnimation(group2);

    animGroup->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionsave_to_SVG_triggered()
{


}
