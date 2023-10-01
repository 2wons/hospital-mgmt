#include "Console.h"
#include "input.hpp"
#include "ctime"
#include "Date.h"

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
   WriteLine("\n[4] ->Back to Main Menu");

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
   WriteLine("[3] Update Item Stock");
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
        case 3: updateStock();
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
    string insurer = "";

    Patient patient;
    patient.lastName = Prompt("Enter last name: ");
    patient.firstName = Prompt("Enter first name: ");

    int month, day, year;

    getNumber("Enter a month of birth (number)", month,   MinMax(1,12));
    getNumber("Enter a day of birth   (number)",   day,   MinMax(1, 31));
    getNumber("Enter a year of birth  (number)",  year,   MinMax(1700, 2099));

    patient.dob = formatDate(month, day, year);

    patient.address = Prompt("Enter address: ");

    insurer = Prompt("Enter insurace company (leave blank if none): ");

    patient.setInsurer(insurer);

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

    record.date         = Date().getDate(TODAY);
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
  
    record.treatment = Prompt("Enter Treatments: ");

    if (patient->hasInsurer())
    {
        Claim claim(record, totalCost, patient->getInsurer());
        claimsdb.add(claim);
    }
    else
    {
        patient->balance += totalCost;
    }
    recordsdb.add(record);
}

void Console::addItem()
{
    WriteLine("[Adding New Medicine Item]\n");
    cin.ignore();

    Item item;
    item.Name = Prompt("Enter Medicine name: ");

    getNumber("Enter medicine Quantiy:", item.Quantity, MinMax(1, -1));
    getNumber("Enter medicine Cost:", item.Quantity, MinMax(1, -1));

	inventorydb.add(item);
    WriteLine("Medicine Item successfully added.");
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

void Console::updateStock()
{
    int updateChoice;
    int ItemId, quantity;

    cout << "[Update Stock]\n" << endl;

    if (inventorydb.all().empty()) {
        cout << "No Items in Inventory";
        return;
    }

    getNumber("Enter ItemID to update: ", ItemId, MinMax(1,999));
    
    auto item = inventorydb.find(ItemId);

    cout << "Would you like to pull[1] or  add[2] stock\n";
    cin >> updateChoice;

    if (updateChoice == 1 && !item->canPull()) {
        cout << "Item is not available";
        return;
    }

    string action = "Enter number of items to ";
    action  += updateChoice == 1 ? "pull: " : "add: ";

    int max = updateChoice == 1 ? item->Quantity : -1;
    getNumber(action, quantity, MinMax(1, max));

    switch (updateChoice)
    {
        case 1: item->pull(quantity); break;
        case 2: item->add(quantity);  break;
    }

    cout << "\n[Item succesfully updated]\n";
    cout << "Item [" + item->Name + "] new quantity: ";
    cout << to_string(item->Quantity);

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

    const auto claims = claimsdb.where(
        [&patientId](const Claim& c) { return c.getPatientId() == patientId;});

    cout << "Patient ID    : " << it->getID()   << endl;
    cout << "Last Name     : " << it->lastName  << endl;
    cout << "First Name    : " << it->firstName << endl;
    cout << "Date of Birth : " << it->dob       << endl;
    cout << "Balance($)    : " << it->balance   << endl;
    cout << "Address       : " << it->address   << endl << endl;

    cout << "\n[Medical History]\n";

    prettyTable({
        "id", 
        "patientid", 
        "departmentid", 
        "date",
        "diagnosis",
        "prescriptions",
        "treatments"},
        records);

    cout << "\n[Insurance Claims]\n";
    
    prettyTable({
        "id",
        "patientid", 
        "to_insurer", 
        "for_services", 
        "date_last_updated",
        "totalCost",
        "status"
    }, claims);

}

void Console::messages()
{
   WriteLine("----Messages[Doctor to Doctor]-----");
   WriteLine("[1] Send New Message              ");
   WriteLine("[2] View all                      ");
   WriteLine("[3] View my inbox                 ");
   WriteLine("\n[4] ->Back to Main Menu         ");

   int choice; cin.clear(); cin.ignore();
   getNumber("input choice > ", choice, MinMax(1,4));

   Clear();

   switch (choice)
    {
        case 1: addMessage();
            break;
        case 2: viewAllMessages();
            break;
        case 3: viewInbox();
            break;
        case 4: return;
            break;

        default: WriteLine("invalid");
    }
}

void Console::addMessage()
{
    cout << "[Compose New Message to Doctor]\n" << endl;
    int sender, receiver;
    std::vector<Doctor> all = doctorsdb.all();

    getNumber("From[Your Doctor id]: ", sender, all);
    getNumber("To[Receiver Doctor id]: ", receiver, all);

    std::string body;
    body = Prompt("Write Message: \n --> ");

    auto it = doctorsdb.find(sender);
    string passkey = Prompt("Enter doctor passkey to confirm: ");

    if (passkey != it->getPasskey())
    {
        cout << "[!Invalid passkey.]" << endl;
        return;
    }

    messagesdb.add({sender, receiver, body});
    cout << "[Message Successfully added]" << endl;

}

void Console::viewInbox()
{
    cout << "[View your messages]\n" << endl;

    int doctorid; cin.ignore();
    getNumber("Enter Doctor id: ", doctorid, MinMax(1,999));

    auto doctor = doctorsdb.find(doctorid);

    if (doctor == doctorsdb.all().end()) {
        WriteLine("Doctor does not exist");
        return;
    }

    string passkey = Prompt("Enter doctor passkey to confirm: ");
    
    if (passkey != doctor->getPasskey())
    {
        cout << "[!Invalid passkey.]" << endl;
        return;
    }

    const auto messages = messagesdb.where(
        [&doctorid](const Message& m) {return m.getReceiverID() == doctorid;});
    
    cout << "[Received Messages]\n\n";
    
    prettyTable({
        "id",
        "sender_id",
        "receiver_id",
        "body"
    }, messages, 1);

}

void Console::viewAllMessages()
{
    prettyTable({
        "id",
        "sender_id",
        "receiver_id",
        "body"
    }, messagesdb.all(), 1);
}

void Console::appointments()
{
   WriteLine("----Messages[Doctor to Doctor]-----");
   WriteLine("[1] Make Appointment              ");
   WriteLine("[2] Cancel Appointment            ");
   WriteLine("\n[3] ->Back to Main Menu         ");

   int choice; cin.clear(); cin.ignore();
   getNumber("input choice > ", choice, MinMax(1,3));

   Clear();

   switch (choice)
    {
        case 1: addAppointment();
            break;
        case 2: cancelAppointment();
            break;
        case 3: return;
            break;

        default: WriteLine("invalid");
    }
}

void Console::addAppointment()
{
    cout << "[Add appointment (automatic doctor patient matching)]" << endl;

    int patientid, deptid;
    string subject, date;

    getNumber("Enter Patient ID: ", patientid, MinMax(1,999));
    
    auto patient = patientsdb.find(patientid);

    if (patient == patientsdb.all().end())
    {
        cout << "\n[Invalid patient id]";
        return;
    }

    WriteLine("Available departments: ");
    for (auto& department : departmentsdb.all())
        cout << department.getID() << ": " << department.dptname << endl;
    
    getNumber("Enter Department id: ", deptid, departmentsdb.all());

    std::vector<Doctor> doctors = doctorsdb.where(
        [&deptid](const Doctor& d) { return d.departmentid == deptid; });

    if (doctors.empty()) {
        cout << "No available doctors";
        return;
    }
    
    int min = doctors[0].numAppointments;
    Doctor selectedDoctor = doctors[0];

    for (auto doc : doctors) {
        if (doc.numAppointments < min)
            selectedDoctor = doc;
    }

    date = Date().getDate(TOMORROW);
    int hour = 0;

    auto doctor = doctorsdb.find(selectedDoctor.getID());

    while (true)
    {
        // try to book the appointment at current date
        hour = doctor->book_appointment(date);
        if (hour != -1);
            break;
        // current date is fully booked, check next day
        date = Date()
                .setDate(date)
                .increment()
                .getString();
    }
    
    cout << "---------------------------" << endl;
    cout << "[New appointment created]" << endl;

    cout << "Patient: " << patient->fullName()  << endl;
    cout << "Doctor: "  << doctor->fullName()   << endl;
    cout << "Date: "    << date                 << endl ;
    cout << "Time: "    << Date().getHour(hour) << endl ;

    cout << "What is the subject of the appointment? \n -->  ";
    subject = Prompt("Enter appointment subject: ");

    appointmentsdb.add({patientid, doctor->getID(), date, hour, subject});
    doctor->numAppointments += 1;
    
    cout << "\n[Appointment successfully created]" << endl;

}

void Console::cancelAppointment()
{
    cout << "[Add appointment (automatic doctor patient matching)]" << endl;
    int appt_id;
    getNumber("Enter apopintment id: ", appt_id, MinMax(1,999));
    auto it = appointmentsdb.find(appt_id);

    if (it == appointmentsdb.all().end()) {
        cout << "appointment does not exist" << endl;
        return;
    }

    appointmentsdb.remove(appt_id);

    cout << "\n[Appointment successfully cancelled]" << endl;

}

void Console::billings()
{
    WriteLine("--------Billings---------");
    WriteLine("[1] Manage Claim         ");
    WriteLine("\n[2] ->Back to Main Menu");
    WriteLine("-------------------------");

    int choice;
    getNumber("input choice > ", choice, MinMax(1,2));

    Clear();
    
    switch (choice)
    {
        case 1 : manageClaim(); break;
        case 2: return;
    }
}

void Console::manageClaim()
{
    cout << "[Manage Claim]\n" << endl;

    if (claimsdb.all().empty()) {
        cout << "No claims available";
        return;
    }

    int claimId, option;
    getNumber("Enter claim id: ", claimId, MinMax(1,-1));

    auto claim = claimsdb.find(claimId);
    if (claim == claimsdb.all().end()) {
        cout << "Claim not found";
        return;
    }

    auto patient = patientsdb.find(claim->getPatientId());

    Table table = claim->toTable();
    cout << table << endl << endl;

    cout << "What would you like to do?\n";
    cout << "[1] nothing [2] Approve [3] Deny\n\n";

    getNumber("Enter option: ", option, MinMax(1,3));
    string msg;

    switch (option)
    {
        case 1: msg = "\nNothing to do"; break;

        case 2: claim->approve(); 
                msg = "\nClaim Approved";
                break;

        case 3: claim->deny();
                patient->owe(claim->getCost());
                msg = "\nClaim Denied";
                break;
    }

    cout << msg << endl;
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
    //patientsdb.save();
    //inventorydb.save();
    //departmentsdb.save();
    //recordsdb.save();
    //messagesdb.save();
    //appointmentsdb.save();
    //doctorsdb.save();
    claimsdb.save();
}