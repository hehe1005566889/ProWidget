#include "PWProjectLoader.h"

#include <QUrl>
#include <QFile>
#include <QDir>

#include "globals.h"

namespace pwfile
{

PWProjectLoader::PWProjectLoader(const QString &path)
    : path(path)
{

}

bool PWProjectLoader::Read()
{
    QUrl url(path);
    if(url.isValid())
        return ReadNet();

    QDir folder(path);
    if(!folder.exists())
        THROW(PWDocEXCP());

    if(!QFile::exists(folder.path() + "\\index.json"))
        THROW(PWDocEXCP());
}

bool PWProjectLoader::ReadNet()
{
    Error("Not Support Yet At [PWProjectLoader::ReadNet]");
    return false;
}

}
