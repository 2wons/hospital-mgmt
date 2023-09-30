#pragma once

#include <map>
#include <string>

using std::map;
using std::string;
using std::to_string;


class Date 
{
private:
    int day;
    int month;
    int year;
    std::map<int, int> daysInMonth = 
    {
        {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
        {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };

    bool isLeapYear(int year);

public:
    Date();

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    string getString();

    string getHour(const int hour);

    Date setDate(const std::string& date);

    Date increment();
};