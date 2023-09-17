#include <iostream>
#include <vector>
#include <fstream>

#include "json.hpp"
#include "Patient.h"
#include "Record.h"

int main()
{
    Db<Patient> pdb("patients.json");
    pdb.load();

    std::vector<Patient> test = pdb.all();
    for (auto v : test)
    {
        std::cout << v.address << std::endl;
    }
    
    string teste;

    std::cin >> teste;
}