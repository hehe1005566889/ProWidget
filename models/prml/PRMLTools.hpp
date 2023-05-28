#ifndef PRMLTOOLS_HPP
#define PRMLTOOLS_HPP

#include "globals.h"

namespace prml
{

class PRMLTools
{
public:
    static void ParsePos(const QString& str, int &x, int &y)
    {
        if(!str.contains(","))
            THROW(PWDocException());

        auto items = str.split(",");
        if(items.count() != 2)
            THROW(PWDocException());

        x = items[0].toInt();
        y = items[1].toInt();
    }

    static void ParsePos(const QString& str, int &x, int &y, int &w, int &h)
    {
        if(!str.contains(","))
            THROW(PWDocException());

        auto items = str.split(",");
        if(items.count() != 4)
            THROW(PWDocException());

        x = items[0].toInt();
        y = items[1].toInt();
        w = items[2].toInt();
        h = items[3].toInt();
    }

    static void ParseBoolean(const QString& str, bool &result)
    {
        if(str.contains("true") || str.contains("false"))
            result = (str == "true");
        else if(str == "1")
            result = true;
        else if(str == "0")
            result = false;
        else
            THROW(PWDocEXCP());
    }
};

}

#endif // PRMLTOOLS_HPP
