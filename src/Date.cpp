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

string Date::getDate(DateRange date)
{
     // Get the current time
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();

    // Add one day if tomorrow is true
    if (date == TOMORROW)
    {
        currentTime += std::chrono::hours(24);
    }

    // Convert the time_point to a time_t for formatting
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

    // Convert to a struct tm for formatting
    std::tm *currentTime_tm = std::localtime(&currentTime_t);

    // Format the date
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", currentTime_tm);

    return buffer;
}