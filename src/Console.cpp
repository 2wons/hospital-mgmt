#include "Console.h"

void Console::test(std::string text) 
{ 
    std::cout << "in development" << std::endl; 
}

void Console::displayMenu()
{
    WriteLine( "Medical City real");
    WriteLine( "-----------------");
    WriteLine( "[1] Patients     ");
    WriteLine( "[2] Doctors      ");
    WriteLine( "[3] Inventory    ");
    WriteLine( "[4] Md Records   ");
    WriteLine( "[5] add Billing  ");
    WriteLine( "[6] Schedule     ");
    WriteLine( "[7] Message      ");
    WriteLine( "[999] quit       ");
    WriteLine( "-----------------");
}

void Console::patients()
{
    WriteLine("--------Patients---------");
    WriteLine("[1] Add new patient      ");
    WriteLine("[2] View all             ");
    WriteLine("[3] search               ");
    WriteLine("[4] update               ");
    WriteLine("\n[5] ->Back to Main Menu");
    WriteLine("-------------------------");
    WriteLine("input choice > ");

    // @TODO clear menu after choice

    int choice = 0;
    std::cin >> choice;

    if (choice == 1)
    {
        WriteLine("choice1");
        // add new patient
    }
    else if (choice == 2)
    {
        WriteLine("Viewing patients");
        std::vector<Patient> results = patientsdb.all();

        for (auto& patient : results)
            patient.print();
    }
    
  
}

void Console::doctors()
{
   WriteLine("----Doctors-----");
   WriteLine("[1] Add new doctor");
   WriteLine("[2] View all");
   WriteLine("[3] Search");
   WriteLine("\n[5] ->Back to Main Menu");
}

void Console::inventory()
{
   WriteLine("----Inventory-----");
   WriteLine("[1] Add new medicine");
   WriteLine("[2] View all");
   WriteLine("[3] Manage");
   WriteLine("\n[5] ->Back to Main Menu");
}

void Console::medical()
{
   WriteLine("----Medical Records-----");
   WriteLine("[1] Add new record");
   WriteLine("[2] View by department");
   WriteLine("\n[5] ->Back to Main Menu");
}

void Console::WriteLine(const string& prompt, int spaces)
{
    cout << std::string(spaces, ' ') << prompt << "\n";
}

void Console::Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

int Console::randomID(const int& idv)
{
    return 0;
}