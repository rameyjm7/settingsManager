# settingsManager
Save and load values from a file and use them in functions

//! header file below

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
