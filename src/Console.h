#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

#include "Db.hpp"
#include "Patient.h"
#include "Record.h"

using namespace std;

/** class to handle console interactions
 */
class Console 
{
public:

    Console() : patientsdb("patients.json") 
    {
        //test data
        /* Patient patient1(1, "John Doe", "Doe", "John", "1990-01-15", "123 Main St");
        Patient patient2(2, "Jane Smith", "Smith", "Jane", "1985-05-20", "456 Elm St");
        patientsdb.add(patient1);
        patientsdb.add(patient2); */

    }
        
    /** Display Main Menu Option
     *  @author Programmer 1
     */
    void displayMenu();

    void test(std::string text);

    void patients();

    void doctors();

    void inventory();

    void medical();

    /** Write string to console
     *  @param prompt string to display
     *  @param spaces no. of left spaces
     */
    static void WriteLine(const string& prompt, int spaces = 0);

    /** Clears the console
     */
    static void Clear();

private:
    Db<Patient> patientsdb;

    /** Generate a random 3 digit number
     *  @author Programmer 2
     *  @param idv 0 for video id, >0 for customer
     *  @return (int) generated id number
     */
    int randomID(const int& idv);
};