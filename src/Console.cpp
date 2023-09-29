#include "Console.h"
#include "input.hpp"
/*

1/ retrieve doctors from that department
2/ find doctor with least amnt of appointments

 */

void Console::test(std::string text) 
{ 
    std::cout << text << " in development" << std::endl;
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

    Clear();

    switch (choice)
    {
        case 1: addPatient();
            break;
        case 2: viewPatients();
            break;
        case 3: findPatient();
            break;
        case 4: test("4");
            break;
        case 5: WriteLine("exit");
            break;

        default: WriteLine("invalid");
    }
}

void Console::doctors()
{
   WriteLine("----Doctors-----         ");
   WriteLine("[1] Add new doctor       ");
   WriteLine("[2] View all             ");
   WriteLine("[3] Search               ");
   WriteLine("\n[5] ->Back to Main Menu");

   int choice = 0;
   std::cin >> choice;

   Clear();

   switch (choice)
    {
        case 1: addDoctor();
            break;
        case 2: viewDoctors();
            break;
        case 3: test("3");
            break;
        case 4: test("4");
            break;

        default: WriteLine("invalid");
    }
}

void Console::inventory()
{
   WriteLine("----Inventory-----");
   WriteLine("[1] Add new medicine");
   WriteLine("[2] View all");
   WriteLine("[3] Manage");
   WriteLine("\n[4] ->Back to Main Menu");

   int choice;
   getNumber("input choice > ", choice, MinMax(1,4));

   Clear();

   switch (choice)
    {
        case 1: addItem();
            break;
        case 2: viewItems();
            break;
        case 3: test("3");
            break;
        case 4: return;
            break;

        default: WriteLine("invalid");
    }
}

void Console::medical()
{
   WriteLine("----Medical Records-----");
   WriteLine("[1] Add new record");
   WriteLine("[2] View by department");
   WriteLine("\n[5] ->Back to Main Menu");

   int choice = 0;
   cin >> choice; 

   Clear();

   switch (choice)
   {
        case 1: addRecord(); 
            break;
        case 2: viewDepartmentRecords(); 
            break;
   }
}

void Console::addPatient()
{
    WriteLine("[Adding New Patient]\n");
    cin.ignore();

    Patient patient;
    patient.lastName = Prompt("Enter last name: ");
    patient.firstName = Prompt("Enter first name: ");

    int month, day, year;

    getNumber("Enter a month of birth (number)", month,   MinMax(1,12));
    getNumber("Enter a day of birth   (number)",   day,   MinMax(1, 31));
    getNumber("Enter a year of birth  (number)",  year,   MinMax(1700, 2099));

    patient.dob = formatDate(month, day, year);
;
    patient.address = Prompt("Enter address: ");

    patientsdb.add(patient);
}

void Console::addDoctor()
{
    WriteLine("[Adding New Doctor]\n");
    cin.ignore();

    Doctor doctor;

    doctor.lastName  = Prompt("Enter last name: ");
    doctor.firstName = Prompt("Enter first name: ");

    WriteLine("Available departments: ");
    for (auto& department : departmentsdb.all())
        cout << "[" << department.getID() << "]" << department.dptname << endl;

    getNumber("Enter department id: ", doctor.departmentid, departmentsdb.all());

    doctorsdb.add(doctor);
    WriteLine("\n[Doctor successfully added].");
}

void Console::addRecord()
{
    WriteLine("[Adding New Patient Medical Record]\n");
    Record record;
    cin.ignore();
    
    getNumber("Enter patient id: ",    record.patientID,    patientsdb.all());

    WriteLine("Available departments: ");
    for (auto& department : departmentsdb.all())
        cout << department.getID() << ": " << department.dptname << endl;

    getNumber("Enter department id: ", record.departmentid, departmentsdb.all());

    record.date         = Prompt("Enter date: ");
    record.diagnosis    = Prompt("Enter diagnosis: ");

    prettyTable({"id", "name", "quantity", "cost"}, inventorydb.all());

    WriteLine("----------Prescriptions---------");
    cout << "How many items to add? ";
    int count;
    cin >> count;
    WriteLine("--------------------------------");
    auto patient = patientsdb.find(record.patientID);

    cin.ignore();
    double totalCost;
    for (int i = 0; i < count; i++)
    {
        int itemid, quantity;
        getNumber("Enter item id: ", itemid, inventorydb.all());
        auto item = inventorydb.find(itemid);
        getNumber("Enter quantity: ", quantity, MinMax(1, item->Quantity));
        record.prescriptions[item->Name] = quantity;
        item->Quantity -= quantity;
        totalCost += item->Cost * quantity;
        WriteLine("-------------------------");
    }
    WriteLine("-------------------------");
    //@TODO make proper function for this
    // maybe cost shouldn't be added if the patient has insurance
    patient->balance += totalCost;

    record.treatment = Prompt("Enter Treatments: ");
    recordsdb.add(record);
}

void Console::addItem()
{
    WriteLine("[Adding New Medicine Item]\n");
    cin.ignore();

    Item item;
    item.Name = Prompt("Enter Medicine name: ");

    getNumber("Enter medicine Quantiy:", item.Quantity, MinMax(1, 999));
    getNumber("Enter medicine Cost:", item.Quantity, MinMax(1, 999));

	inventorydb.add(item);
    WriteLine("Medicin Item successfully added.");
}

void Console::viewDepartmentRecords()
{
    WriteLine("[Viewing Records by Department]\n");

    int deptid;
    cin.ignore();

    getNumber("Enter department id: (number): ", deptid, departmentsdb.all());
    std::vector<Record> results = recordsdb.where(
        [&deptid](const Record& r) { return r.departmentid == deptid; });
    
    if (results.empty()) {
        WriteLine("No records found");
        return;
    }

    prettyTable({
        "id", 
        "patientid", 
        "departmentid", 
        "date",
        "diagnosis",
        "prescriptions",
        "treatments"},
        results);
}

void Console::viewPatients()
{
    WriteLine("Viewing patients");

    prettyTable({"id",
                 "lastname",
                 "firstname",
                 "dob",
                 "address",
                 "balance"},
                patientsdb.all());
}

void Console::viewDoctors()
{
    WriteLine("[Viewing doctors]\n");
    prettyTable({"id",
                 "lastname",
                 "firstname",
                 "departmentid"},
                doctorsdb.all());
}

void Console::viewItems()
{
    WriteLine("[Viewing Medicine Items]\n");
    prettyTable({"ID", "Name", "Quantity", "Cost"}, inventorydb.all());
}

void Console::findPatient()
{
    int patientId; cin.ignore();
    getNumber("Enter patient id: (number): ", patientId, MinMax(1,999));
    auto it = patientsdb.find(patientId);

    if (it == patientsdb.all().end()) {
        WriteLine("Patient does not exist");
        return;
    }
    const auto records = recordsdb.where(
        [&patientId](const Record& r) {return r.patientID == patientId;});

    cout << "Patient ID    : " << it->getID()   << endl;
    cout << "Last Name     : " << it->lastName  << endl;
    cout << "First Name    : " << it->firstName << endl;
    cout << "Date of Birth : " << it->dob       << endl;
    cout << "Address       : " << it->address   << endl << endl;

    prettyTable({
        "id", 
        "patientid", 
        "departmentid", 
        "date",
        "diagnosis",
        "prescriptions",
        "treatments"},
        records);

}

void Console::WriteLine(const string& prompt, int spaces)
{
    cout << std::string(spaces, ' ') << prompt << "\n";
}

void Console::pause()
{
    //cin.ignore();
    cin.get();
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

void Console::onExit()
{
    patientsdb.save();
    departmentsdb.save();
    recordsdb.save();
}