#include "Date.h"

Date::Date()
{

}

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

string Date::getString() 
{
    return {to_string(year) + "-" + to_string(month) + "-" + to_string(day)};
}

Date Date::setDate(const std::string& date) 
{
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return *this;
}

Date Date::increment() 
{
    day++;
    if (month == 2 && isLeapYear(year)) 
    {
        if (day > 29) 
        {
            day = 1;
            month++;
        }
    } else if (day > daysInMonth[month]) 
    {
        day = 1;
        month++;
    }

    if (month > 12) 
    {
        month = 1;
        year++;
    }

    return *this;
}

string Date::getHour(const int hour)
{
    int new_hour  = hour % 12;
    string ampm;

    if (new_hour == 0) 
    {
        new_hour = 12;  
        ampm = "AM";
    } else if (hour < 12) 
    {
        ampm = "AM";
    } else 
    {
        ampm = "PM";
    }

    return {to_string(new_hour)+ampm};

}