#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>
#include <QMenu>
#include <stdlib.h>
#include <QAction>

class SettingMenu : public QMenu
{
    Q_OBJECT
    QAction* monitor_off;
    QAction* shutdown;
public:
    explicit SettingMenu(QWidget *parent = nullptr);

signals:

public slots:
    void monitorOff();
    void shutDown();
    void timeOver();

};

#endif // SETTINGMENU_H
