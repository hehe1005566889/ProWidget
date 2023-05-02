#ifndef PWPROJECTLOADER_H
#define PWPROJECTLOADER_H

#include <QString>
#include <QList>

namespace pwfile {

struct PWProject
{
    QString Name;
    QString Author;
    int Version;

    QList<std::pair<const QString&, const QString&>> Dependencies;

    QString indexPageContent;
    QString mainCodeContent;
};

class PWProjectLoader
{
public:
    PWProjectLoader(const QString& path);

    bool Read();
    void ReadFolder(PWProject& project);

private:
    bool ReadNet();

private:
    QString path;

};

}

#endif // PWPROJECTLOADER_H
