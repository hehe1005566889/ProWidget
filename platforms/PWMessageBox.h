#ifndef PWMESSAGEBOX_H
#define PWMESSAGEBOX_H

#include <QString>

class PWMessageBox
{
public:
    static void Basic   (const QString& title, const QString& content);
    static void Critical(const QString& title, const QString& content);
    static void Warning (const QString& title, const QString& content);
};

#endif // PWMESSAGEBOX_H
