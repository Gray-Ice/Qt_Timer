#include "settingmenu.h"

static int choice = 0;
SettingMenu::SettingMenu(QWidget *parent) : QMenu(parent)
{
    monitor_off = addAction("Monitor Off(Default)");
    shutdown = addAction("ShutDown");
}

void SettingMenu::monitorOff()
{
    choice = 0;
}

void SettingMenu::shutDown()
{
    choice = 1;
}

void SettingMenu::timeOver()
{
    switch (choice) {
    // monitor off
    case 0:
        // this command will close your monitor.But it needs xinput.
        system("ls");
        system("xset dpms force off");
        break;
        ;
    case 1:
        /*
         * This command will close your computer.On Arch linux,
         * it works well. But in kali or centOS, it needs root.
         * Because those operating systems under Debian need root
         * to execute this command.
        */
        system("shutdown 0");
        break;
    default:
        break;
    }
}
