#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "tabulate.hpp"

using std::cin;
using std::cout;
using std::string;
using std::vector;

using namespace tabulate;

using Row_t = Table::Row_t;

struct MinMax
{
    MinMax(int min, int max)
        : min(min), max(max) {}

    int min;
    int max;
};

bool isNumber(std::string str)
{
    try
    {
        std::stoi(str);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

std::string Prompt(std::string prompt, bool canEmpty = false)
{
    std::string input;
    std::cout << prompt << ": ";
    std::getline(std::cin, input);
    return input;
}

inline void getNumber(const std::string &prompt, int &var, const MinMax &bounds)
{
    string tmp;

    while (true)
    {
        cout << prompt << ": ";
        getline(cin, tmp);

        if (!isNumber(tmp))
        {
            std::cout << "inValid number: " << tmp << std::endl;
            continue;
        }

        var = stoi(tmp);

        if (bounds.max == -1 && var >= 1) break;

        if (bounds.max != -1 && var >= bounds.min && var <= bounds.max)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid number ("
                 << bounds.min << "-"
                 << bounds.max << ")\n\n";
        }
    }
}

template <typename T>
inline void getNumber(const std::string &prompt, int &var, std::vector<T> myList)
{
    string tmp;
    while (true)
    {
        cout << prompt << ": ";
        std::getline(std::cin, tmp);

        if (!isNumber(tmp))
        {
            std::cout << "inValid number: " << tmp << std::endl;
            continue;
        }

        var = stoi(tmp);

        auto it = std::find(myList.begin(), myList.end(), var);

        if (it != myList.end())
            break;

        std::cout << "Please enter a valid id" << std::endl;
        cin.clear();
    }
}

std::string formatDate(int month, int day, int year)
{
    // Convert integers to strings and format the date
    std::string formattedDate = std::to_string(month) + "-" + std::to_string(day) + "-" + std::to_string(year);
    return formattedDate;
}

template <class T>
void prettyTable(vector<string> headers, vector<T> collection, int mode = 0)
{
    Table table;
    table.format().locale("C");

    table.add_row(Row_t(headers.begin(), headers.end()));

    for (const auto &v : collection)
    {
        vector<string> row = v.to_row();

        table.add_row(Row_t(row.begin(), row.end()));
    }

    // center-align and color header cells
    for (size_t i = 0; i < headers.size(); ++i)
    {
        table[0][i].format()
            .font_color(Color::yellow)
            .font_align(FontAlign::center)
            .font_style({FontStyle::bold});
    }

    // set last column to a 40 max width
    if (mode > 0)
        table.column(headers.size() - 1).format().width(40);

    std::cout << table << std::endl;
}