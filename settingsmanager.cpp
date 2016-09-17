#include "settingsmanager.h"

SettingsManager::SettingsManager( QString filename, bool DEBUGMODE)
{
    bDEBUGMODE = DEBUGMODE;
    settingsFile = filename;
    nameArray = new QStringList;
    valueArray = new QStringList;
}

//! updates the file with the current values from the
void SettingsManager::saveSettings()
{
    QFile file(settingsFile);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        for(int i=0; i<nameArray->count(); i++)
        {

            stream << nameArray->at(i) << "," << valueArray->at(i) << endl;
            if(bDEBUGMODE) qDebug() << "Writing" << nameArray->at(i) << "," << valueArray->at(i);

        }
    }
    else qDebug() << "Could not open file for writing";
    file.close();
}

//! reads the settings file, appends an array of strings, passes it to be parsed
//! which will update settings such as registry values
void SettingsManager::loadSettings()
{
    QStringList temp;
    QFile settings(settingsFile);
    if (settings.open(QIODevice::ReadOnly))
    {
        QTextStream in(&settings);
        while (!in.atEnd())
        {
            temp.append(in.readLine());
        }
        parseSettings(temp);
    }
    else qDebug() << "Could not open file for reading";
    settings.close();
}
//! pass in stringlist, each item in list is the string from one line of the file
//! parse by splitting commas, item index with switch for setting the variables holding the settings
void SettingsManager::parseSettings(QStringList settings)
{
    valueArray->clear();
    nameArray->clear();
    for(int i=0; i<settings.count(); i++)
    {
        nameArray->append(settings.at(i).split(",").at(0));
        valueArray->append(settings.at(i).split(",").at(1));
        if(bDEBUGMODE) qDebug() << "From file read: " << nameArray->at(nameArray->count()-1)
                                << "," << valueArray->at(nameArray->count()-1);
    }
}


int SettingsManager::count()
{
    return nameArray->count();
}

void SettingsManager::addSetting(QString settingName, int value)
{
    nameArray->append(settingName);
    valueArray->append(QString::number(value));

}
void SettingsManager::addSetting(QString settingName, float value)
{
    nameArray->append(settingName);
    valueArray->append(QString::number(value));

}
void SettingsManager::addSetting(QString settingName, QString value)
{
    nameArray->append(settingName);
    valueArray->append(value);

}
void SettingsManager::printSettings()
{
    loadSettings();
    for(int i=0;i<nameArray->count();i++)
        qDebug() << nameArray->at(i) << valueArray->at(i);
}

QString SettingsManager::nameAt(int index)
{
    loadSettings();
    return nameArray->at(index);
}
int SettingsManager::valueAt(int index)
{
    loadSettings();
    return valueArray->at(index).toInt();
}
void SettingsManager::getValues(QStringList * listValues)
{
    loadSettings();
    listValues = valueArray;
}
void SettingsManager::getNames(QStringList * names)
{
    loadSettings();
    names = nameArray;
}

