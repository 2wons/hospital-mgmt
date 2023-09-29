#include <iostream>
#include <vector>
#include <fstream>

#include "json.hpp"
#include "Console.h"

int main()
{
    int choice = 0;
    Console console;

    do
    {
        console.Clear();

        console.displayMenu();

        std::cout << "type input---> ";
        std::cin >> choice;

        console.Clear();

        switch (choice)
        {
        case 1:
            console.patients();
            break;

        case 2:
            console.doctors();
            break;

        case 3:
            console.inventory();
            break;

        case 4:
            console.medical();
            break;
        
        case 5:
            console.test("billing");
            break;
        
        case 6:
            console.test("schedule");
            break;
        
        case 7:
            console.messages();
            break;

        default:
            break;
        }

        if (choice != 999)
        {
            cout << "Press <enter> to continue > ";

            cin.ignore();
            cin.get();
        }

        console.Clear();

    } while (choice != 999);

    console.onExit();
}