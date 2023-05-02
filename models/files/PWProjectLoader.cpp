#include "PWProjectLoader.h"

#include <QUrl>
#include <QFile>
#include <QDir>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "globals.h"

namespace pwfile
{

#define OPEN_FILE(file) \
if(!file.open(QFile::ReadWrite)) \
THROW(PWIOEXCEP());
#define KILL_FILE(file) \
file.close();

PWProjectLoader::PWProjectLoader(const QString &path)
    : path(path)
{

}

bool PWProjectLoader::Read()
{
    //QUrl url(path);
    //if(url.isValid())
    //    return ReadNet();

    QDir folder(path);
    if(!folder.exists())
        THROW(PWDocEXCP());

    if(!QFile::exists(folder.path() + "/index.json"))
        THROW(PWDocEXCP());

    return true;
}

void PWProjectLoader::ReadFolder(PWProject &project)
{
    QDir folder(path);
    if(!folder.exists())
        THROW(PWDocEXCP());

    QFile file(folder.path() + "/index.json");
    if(!file.exists())
        THROW(PWDocEXCP());
    OPEN_FILE(file);

    auto root = QJsonDocument::fromJson(file.readAll()).object();
    KILL_FILE(file);

    auto app  = root["app"].toObject();

    project.Name    = app["name"   ].toString("UnKnown Name");
    project.Author  = app["author" ].toString("UnKnwon Author");
    project.Version = app["version"].toInt(1);

    auto path = root["ui"].toString();
    QFile mainUI(folder.path() + "/" + path);
    if(!mainUI.exists())
        THROW(PWDocEXCP());
    OPEN_FILE(mainUI);

    project.indexPageContent = mainUI.readAll();
    KILL_FILE(mainUI);

    auto cpath = root["code"].toString();
    QFile mainCode(folder.path() + "/" + cpath);
    if(!mainCode.exists())
        THROW(PWDocEXCP());
    OPEN_FILE(mainCode);
    project.mainCodeContent = mainCode.readAll();
    KILL_FILE(mainCode);
}

bool PWProjectLoader::ReadNet()
{
    Error("Not Support Yet At [PWProjectLoader::ReadNet]");
    return false;
}

}
