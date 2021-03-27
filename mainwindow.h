#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "settingmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void time_out();

private:
    Ui::MainWindow *ui;
    QTimer* qtmer_p;  // counter
    int minutes;  // class minutes
    int u_m;  // user minutes
    int seconds;  // class seconds
signals:
    void doIt();
};
#endif // MAINWINDOW_H
