#ifndef PWPROJECTLOADER_H
#define PWPROJECTLOADER_H

#include <QString>

namespace pwfile {

class PWProjectLoader
{
public:
    PWProjectLoader(const QString& path);

    bool Read();

private:
    bool ReadNet();

private:
    QString path;

};

}

#endif // PWPROJECTLOADER_H
