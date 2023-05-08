#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QSettings>
#include <QFile>

class Config
{
public:
    Config()
    {
        if(!QFile::exists("system.ini"))
            QFile::copy(":/setting.ini", "system.ini");
        setting = new QSettings("system.ini", QSettings::IniFormat);
    }

public:
    void SetKeyValue(const QString& key, const QString& value) const
    {
        setting->setValue(key, value);
        setting->sync();
    }

    const QVariant GetValue(const QString& key) const
    {
        return setting->value(key, "nil");
    }

private:
    QSettings* setting;
};

static Config* SystemSetting = new Config();

#endif // CONFIG_HPP
