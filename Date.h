#pragma once

class Date
{
private:
    int month;
    int day;
    int year;
public:
    //Default Constructor
    Date();
    //Paramterized Constructor
    Date(int m, int d, int y);

    //Compares the upload date of the movie with the given date.
    bool operator < (const Date& date);
};