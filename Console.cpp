#include "Console.h"

void CLI::displayMenu()
{
    WriteLine("test 1 \n",1);
}

void CLI::viewPatients(std::vector<Patient> lst)
{
    for (auto i : lst)
        i.print();
    
    /* @TODO
     * make one view function for all kinds of data(collection type)
     */
}

void CLI::addPatient(std::vector<Patient>& lst)
{
    Patient patient;
    std::cout << "Patient name: "; std::cin >> patient.name;
    std::cout << "Patient name: "; std::cin >> patient.doctor;
    lst.push_back(patient);
    std::cout << "Patient added.\n";
}

void CLI::viewRecord(std::vector<Record> lst)
{
    for (auto i : lst)
        i.print();
}

void CLI::addRecord(std::vector<Record>& lst)
{
    Record record;
    std::cout << "Patient ID: "; std::cin >> record.PatientID;
    std::cout << "date: "; std::cin >> record.date;
    std::cout << "diagnosis: "; std::cin >> record.diagnosis;
    std::cout << "prescription: "; std::cin >> record.diagnosis;
    std::cout << "Attending Person: "; std::cin >> record.attendingPerson;
    lst.push_back(record);
    std::cout << "Record added.\n";

    /* @TODO
     * check if PatientID and attendingPerson are valid (exists in db)
     * + add treatment field
     */
}

void CLI::appointment()
{
    std::cout << "Patient ID: ";
    std::cout << "( Select department: )";
        std::cout << "[1] Ortophedic: ";
        std::cout << "[2] Cardiology: ";
        std::cout << "[3] Pediatrics: ";
    std::cout << "Department no: ";
    std::cout << "Assigned doctor: ";
    std::cout << "date: ";
    std::cout << "time: ";


    /* @TODO
     * check if PatientID is valid (exists in db)
     * prompt for department
     * assign doctor from department with least amnt of patients
     */

}

void CLI::WriteLine(const string& prompt, int spaces)
{
    cout << std::string(spaces, ' ') << prompt;
}

void CLI::Clear()
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

int CLI::randomID(const int& idv)
{
    return 0;
}