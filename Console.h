#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "Patient.h"
#include "Record.h"

using namespace std;

/** class to handle console interactions
 *  @author lead programmer 
 */
class CLI
{
public:

    CLI() {}
        
    /** \brief Display Main Menu Option
     */
    void displayMenu();

    /** Display all patients
     *  @param lst vector of patients to display
     */
    void viewPatients(std::vector<Patient> lst);

    void addPatient(std::vector<Patient>& lst);

    void addRecord(std::vector<Record>& lst);

    void viewRecord(std::vector<Record> lst);

    void appointment();



    /** Write string to console
     *  @param prompt string to display
     *  @param spaces no. of left spaces
     *  @author Lead Programmer
     */
    static void WriteLine(const string& prompt, int spaces = 0);

    /** \brief Clears the console
     */
    static void Clear();

private:

    /** Generate a random 3 digit number
     *  @author Programmer 2
     *  @param idv 0 for video id, >0 for customer
     *  @return (int) generated id number
     */
    int randomID(const int& idv);
};