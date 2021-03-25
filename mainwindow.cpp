#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QTimer>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      minutes(0),
      seconds(0)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    qtmer_p = new QTimer(this);
    qtmer_p -> setInterval(1000);
    // add about button
    QAction* about = ui->menubar ->addAction("About");
    connect(about, &QAction::triggered, [=](){
       QMessageBox::aboutQt(ui->menubar, "AboutQt");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::cout << "Runnded." << std::endl;
    // this variable let the function knows if the user want to start
    // counter or not.
    static bool status = true;
    connect(qtmer_p, &QTimer::timeout, this, &MainWindow::time_out);
    if(status)
    {

        // get the user minute
        u_m = ui->minNum->value();
        if(!u_m)
        {
            ;
        }
        else
        {
            // reset class minute
            minutes = 0;
            ui->minNum->setValue(0);
            // start counter
            qtmer_p->start();
            // change button
            ui->startButton->setText("Stop!");
            // make spin box not avalibale to user
            ui->minNum->setEnabled(false);
            ui->minNum->hide();
            // change the prompt text
            ui->prompt->setText("<h1>Please Wait...</h1>");
            // hide the time unit
            ui->timeUnit->hide();
            status = false;
        }
    }
    else
    {
        // stop counter
        qtmer_p->stop();
        // make a new counter
        delete qtmer_p;
        qtmer_p = new QTimer;
        qtmer_p->setInterval(1000);
        // reset time values
        minutes = 0;
        seconds = 0;
        // reset button
        ui->startButton->setText("Start!");
        // reset spin box
        ui->minNum->setValue(u_m);
        ui->minNum->setEnabled(true);
        ui->minNum->show();
        ui->timeUnit->show();
        ui->prompt->setText("<h2>How many minutes do you want to wait:</h2>");
        status = true;
    }
}

void MainWindow::time_out()
{
    std::cout << "Time outed." << std::endl;
    seconds += 1;
    QString qs;
    ui->lcdSecond->display(seconds);
    ui->lcdMinute->display(minutes);
    std::cout << "This is minute: " << minutes << std::endl;
    std::cout << "This is second: " << seconds << std::endl;
    if(seconds == 60)
    {
        minutes += 1;
        seconds = 0;
    }
    if(minutes == u_m && u_m != 0)
    {
        emit MainWindow::on_pushButton_clicked();
    }
}
