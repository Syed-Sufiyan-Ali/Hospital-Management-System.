#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Patient {
    string name;
    string illness;
    string id;
    char gender;
    int age;
    int days_admitted;
};

Patient patient[10];
int total_patient = 0;

// Load patients from file
void loadPatients() {
    ifstream file("patients.txt");
    string line;

    while (getline(file, line) && total_patient < 10) {
        stringstream ss(line);
        getline(ss, patient[total_patient].name, '|');
        ss >> patient[total_patient].age;
        ss.ignore();
        ss >> patient[total_patient].gender;
        ss.ignore();
        getline(ss, patient[total_patient].id, '|');
        getline(ss, patient[total_patient].illness, '|');
        total_patient++;
    }

    file.close();
}

// Save patients to file
void savePatients() {
    ofstream file("patients.txt");

    for (int i = 0; i < total_patient; i++) {
        file << patient[i].name << "|"
     << patient[i].age << "|"
     << patient[i].gender << "|"
     << patient[i].id << "|"
     << patient[i].illness << endl;
    }

    file.close();
}
int find_patient_for_bill(string id){
    for (int i = 0; i < total_patient; i++)
{
    if (patient[i].id == id)
    {
        return i;
    }
}

return -1;
}

int main() {
string username , password;
while(true){
cout << "Enter username: " ;
cin >> username;
cout << "Enter password: " ;
cin >> password;

if (username == "hms_sufiyan" && password == "sufiyan123") {
    cout << "Login Successful.\nWelcome to Sufiyan Health Clinic Management System.\n";
    break;
}


else{
    cout << "Login Failed Try again. \n";
}
}
    loadPatients();

    int user_response;
    int admitted_for;

    while (true) {

       cout << "1. Add Patient\n";
       cout << "2. Search Patients\n";
       cout << "3. View All Patients\n";
       cout << "4. Generate Bill\n";
       cout << "5. Delete Patient\n";
       cout << "6. Exit\n";

        cin >> user_response;

        if (user_response == 1) {

            if (total_patient >= 10) {
                cout << "Hospital storage is full.\n";
                continue;
            }
            cin.ignore();
            cout << "Enter patient name: ";
            getline(cin, patient[total_patient].name);

            cout << "Enter patient age: ";
            cin >> patient[total_patient].age;

            cout << "Enter patient gender (M/F): ";
            cin >> patient[total_patient].gender;

            cout << "Enter patient ID: ";
            cin >> patient[total_patient].id;

            cin.ignore();
            cout << "Enter illness: ";
            getline(cin, patient[total_patient].illness);       

bool id_exists = false;

for (int i = 0; i < total_patient; i++)
{
    if (patient[i].id == patient[total_patient].id)
    {
        id_exists = true;
        break;
    }
}

if (id_exists)
{
    cout << "Patient ID already exists.\n";
}
else
{
    total_patient++;

    savePatients();

    cout << "Patient added successfully.\n";
}
        }

        else if (user_response == 2) {

            int search_choice;

cout << "\n===== SEARCH PATIENT =====\n";
cout << "1. Search by Patient ID\n";
cout << "2. Search by Name + ID\n";
cout << "Enter Choice: ";
cin >> search_choice;

bool found = false;

if (search_choice == 1)
{
    string search_id;

    cout << "Enter Patient ID: ";
    cin >> search_id;

    for (int i = 0; i < total_patient; i++)
    {
        if (patient[i].id == search_id)
        {
            found = true;

            cout << "\n===== PATIENT RECORD =====\n";
            cout << "Name: " << patient[i].name << endl;
            cout << "Age: " << patient[i].age << endl;
            cout << "Gender: " << patient[i].gender << endl;
            cout << "ID: " << patient[i].id << endl;
            cout << "Illness: " << patient[i].illness << endl;

            break;
        }
    }
}

else if (search_choice == 2)
{
    string search_name;
    string search_id;

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, search_name);

    cout << "Enter Patient ID: ";
    cin >> search_id;

    for (int i = 0; i < total_patient; i++)
    {
        if (patient[i].name == search_name &&
            patient[i].id == search_id)
        {
            found = true;

            cout << "\n===== PATIENT RECORD =====\n";
            cout << "Name: " << patient[i].name << endl;
            cout << "Age: " << patient[i].age << endl;
            cout << "Gender: " << patient[i].gender << endl;
            cout << "ID: " << patient[i].id << endl;
            cout << "Illness: " << patient[i].illness << endl;

            break;
        }
    }
}

else
{
    cout << "Invalid Search Option.\n";
}

if (!found)
{
    cout << "Patient not found.\n";
}
        }
else if (user_response == 3)
{
    if (total_patient == 0)
    {
        cout << "No patients found.\n";
    }
    else
    {
        cout << "\n===== ALL PATIENT RECORDS =====\n";

        for (int i = 0; i < total_patient; i++)
        {
            cout << "\nPatient #" << i + 1 << endl;
            cout << "Name    : " << patient[i].name << endl;
            cout << "Age     : " << patient[i].age << endl;
            cout << "Gender  : " << patient[i].gender << endl;
            cout << "ID      : " << patient[i].id << endl;
            cout << "Illness : " << patient[i].illness << endl;
            cout << "-----------------------------\n";
        }
    }
}
        else if (user_response == 4) {
            
          string bill_id;
int days_admitted;
int medicine_charges;
int test_charges;

cout << "Enter Patient ID: ";
cin >> bill_id;

int index = find_patient_for_bill(bill_id);

if (index == -1)
{
    cout << "Patient not found.\n";
}
else
{
    cout << "Enter Number of Days Admitted: ";
    cin >> days_admitted;

    cout << "Enter Medicine Charges: ";
    cin >> medicine_charges;

    cout << "Enter Lab/Test Charges: ";
    cin >> test_charges;

    int room_charges = days_admitted * 1000;
    int doctor_fee = 500;

    int total_bill = room_charges
                   + doctor_fee
                   + medicine_charges
                   + test_charges;

    cout << "\n========== Sufiyan Health Clinic ==========\n";
    cout << "Patient Name     : " << patient[index].name << endl;
    cout << "Patient ID       : " << patient[index].id << endl;
    cout << "Illness          : " << patient[index].illness << endl;
    cout << "----------------------h-------------\n";
    cout << "Room Charges     : Rs. " << room_charges << endl;
    cout << "Doctor Fee       : Rs. " << doctor_fee << endl;
    cout << "Medicine Charges : Rs. " << medicine_charges << endl;
    cout << "Lab/Test Charges : Rs. " << test_charges << endl;
    cout << "-----------------------------------\n";
    cout << "Total Bill       : Rs. " << total_bill << endl;
    cout << "===================================\n";
}

        }

else if (user_response == 5)
{
    string delete_id;
    bool found = false;

    cout << "Enter Patient ID to delete: ";
    cin >> delete_id;

    for (int i = 0; i < total_patient; i++)
    {
        if (patient[i].id == delete_id)
        {
            found = true;

            // Shift all patients left
            for (int j = i; j < total_patient - 1; j++)
            {
                patient[j] = patient[j + 1];
            }

            total_patient--;

            savePatients();

            cout << "Patient deleted successfully.\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Patient not found.\n";
    }
}
else if (user_response == 6)
{
    cout << "You have exited the program.\n";
    break; 
}

        else {

            cout << "Invalid option.\n";
        }
    }

    return 0;
}






































































































































































































































































































