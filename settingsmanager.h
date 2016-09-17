#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "settingsmanager_global.h"

#include "QString"
#include "QStringList"
#include "QDebug"
#include "QFile"



class SETTINGSMANAGERSHARED_EXPORT SettingsManager
{

public:
    SettingsManager(QString filename="settings.txt", bool DEBUGMODE=false);
    bool bDEBUGMODE;
    QString settingsFile;
    QStringList * valueArray;
    QStringList * nameArray;


    void addSetting(QString settingName, int value);
    void addSetting(QString settingName, float value);
    void addSetting(QString settingName, double value);
    void addSetting(QString settingName, QString value);
    QString nameAt(int index);
    int valueAt(int index);
    void getValues(QStringList * listValues);
    void getNames(QStringList * names);
    void printSettings();

    void saveSettings();
    void loadSettings();
    void parseSettings(QStringList settings);
    int count();
};

#endif // SETTINGSMANAGER_H
