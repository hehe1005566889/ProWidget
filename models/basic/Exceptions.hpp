#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <QVariant>
#include <QObject>

#define THROW(EXCEPTION) throw EXCEPTION

#define EXCEPTION(...) new Exception(__VA_ARGS__)
#define PRMLEXCEP(...) new PRMLException(__VA_ARGS__)
#define PRLUAEXCP(...) new PRLUAException(__VA_ARGS__)
#define PWDocEXCP(...) new PWDocException(__VA_ARGS__)

#define APP_CATCHER(...) try { __VA_ARGS__; return 0; } catch(...) { qDebug() << "catch exception!"; return -1; }

#define CATCHER(RELOGIC, LOGIC) try { LOGIC } catch(...) { qDebug() << "catch exception!"; RELOGIC }

struct Exception : std::exception
{
    Exception()
        : ExceptionMessage("[Exception] An UnHandled Exception Was Raised"),
          ExceptionObject(0)
    {}
    Exception(const QString& message)
        : ExceptionMessage(message),
          ExceptionObject(0)
    {}
    Exception(const QString& message, const QVariant& obj)
        : ExceptionMessage(message),
          ExceptionObject(obj)
    {}

    QString ExceptionMessage;
    QVariant ExceptionObject;
};

struct PRMLException : Exception
{

};

struct PRLUAException : Exception
{

};

struct PWDocException : Exception
{

};

#endif // EXCEPTIONS_HPP
