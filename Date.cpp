#include "Date.h"

Date::Date()
{
    month = 0;
    day = 0;
    year = 0;
}
//Paramterized Constructor
Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

//Compares the upload date of the movie with the given date.
bool Date::operator < (const Date& date)
{
    if (this->year < date.year)
    {
        return true;
    }
    else if (this->year == date.year)
    {
        if (this->month < date.month)
        {
            return true;
        }
        else if (this->month == date.month)
        {
            if (this->day < date.day)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}