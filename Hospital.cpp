#include <iostream>
using namespace std;

struct Patient {
    string name;
    string illness;
    char gender;
    int age;
    int id;
};

Patient patient[10];

int main() {
    int user_response;
    int total_patient = 0;
    int admitted_for;

    while (true) {
        cout << "===== HOSPITAL MANAGEMENT SYSTEM =====\n\n"
             << "1. Add Patient\n2. View Patients\n3. Generate Bill\n4. Exit\n";
        cin >> user_response;

        if (user_response == 1) {
            cout << "Enter patient name: ";
            cin >> patient[total_patient].name;
            cout << "Enter patient age: ";
            cin >> patient[total_patient].age;
            cout << "Enter patient gender (M or F): ";
            cin >> patient[total_patient].gender;
            cout << "Enter patient ID: ";
            cin >> patient[total_patient].id;
            cout << "Enter illness: ";
            cin >> patient[total_patient].illness;
            total_patient++;
        }
        else if (user_response == 2) {
    if (total_patient == 0) {
        cout << "No patient has been admitted yet.\n";
    } else {
        int search_id;
        cout << "Enter patient ID: ";
        cin >> search_id;

        bool found = false;
        for (int i = 0; i < total_patient; i++) {
            if (patient[i].id == search_id) {
                cout << "Patient: " << patient[i].name
                     << "\nID: " << patient[i].id
                     << "\nAge: " << patient[i].age
                     << "\nGender: " << patient[i].gender
                     << "\nIllness: " << patient[i].illness
                     << "\n_________________________________________\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No patient found with ID " << search_id << ".\n";
    }
}
        else if (user_response == 3) {
            cout << "Enter patient ID: ";
            int search_id;
            cin >> search_id;
            cout << "Enter number of days admitted: ";
            cin >> admitted_for;
            cout << "Total bill: Rs." << admitted_for * 1000 << "\n";
        }
        else if (user_response == 4) {
            cout << "You have exited the program. Thank you!\n";
            break;
        }
        else {
            cout << "Invalid response. Please try again.\n";
        }
    }
	total_patient++;


}