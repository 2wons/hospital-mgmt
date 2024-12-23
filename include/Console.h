#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "tabulate.hpp"

#include "Db.hpp"
#include "entity/Patient.h"
#include "entity/Record.h"
#include "entity/Department.h"
#include "entity/Doctor.h"
#include "entity/Item.h"
#include "entity/Message.h"
#include "entity/Appointment.h"
#include "entity/Claim.h"

using namespace std;

/** class to handle console interactions
 */
class Console 
{
public:

    Console() : 
        patientsdb("patients.json"),
        departmentsdb("departments.json"),
        recordsdb("records.json"),
        doctorsdb("doctors.json"), 
        inventorydb("inventory.json"),
        messagesdb("messages.json"),
        appointmentsdb("appointments.json"),
        claimsdb("claims.json")
    {

    }
        
    /** Display Main Menu Option
     *  @author Programmer 1
     */
    void displayMenu();

    void test(std::string text);

    void patients();

    void addPatient();

    void viewPatients();

    void findPatient();

    void updatePatient();

    void doctors();

    void addDoctor();

    void viewDoctors();

    void inventory();

    void addItem();

    void viewItems();

    void updateStock();

    void medical();

    void addRecord();

    void viewDepartmentRecords();

    void messages();

    void addMessage();

    void viewAllMessages();

    void appointments();

    void addAppointment();

    void cancelAppointment();

    void billings();

    void manageClaim();

    void viewInbox();

    void viewDoctor();

    void onExit();

    bool isAdmin();

    /** Write string to console
     *  @param prompt string to display
     *  @param spaces no. of left spaces
     */
    static void WriteLine(const string& prompt, int spaces = 0);

    /** Clears the console
     */
    static void Clear();

private:
    Db<Patient>         patientsdb;
    Db<Record>          recordsdb;
    Db<Department>      departmentsdb;
    Db<Doctor>          doctorsdb;
    Db<Item>            inventorydb;
    Db<Message>         messagesdb;
    Db<Appointment>     appointmentsdb;
    Db<Claim>           claimsdb;
};