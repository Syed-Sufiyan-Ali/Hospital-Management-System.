#include <iostream>
using namespace std;
struct Patient {

    string name;
    string illness;
    char gender;

    int age;
    int id;
    

};
Patient patient [10];

int main (){
 int user_response;
 int total_patient = 0 ;
 int Addmited_For;
 while (true){
 cout << " ===== HOSPITAL MANAGEMENT SYSTEM ===== \n\n1. Add Patient \n2. View Patients\n3. Generate Bill\n4. dfa ho \n" ;
 
 cin >> user_response;

 if (user_response == 1){
 	cout << "Enter patient name: ";
 	cin >> patient[total_patient].name;
 	cout << "Enter patient age: ";
 	cin >> patient[total_patient].age;
 	cout << "Enter patient gender (press M or F ): ";
 	cin >> patient[total_patient].gender;
 	cout << "Enter patient ID: ";
 	cin >> patient[total_patient].id;
 	cout << "Enter illness: ";
 	cin >> patient[total_patient].illness;
 	total_patient++;
 }
 

 else  if (user_response == 2){
    if (total_patient == 0){
		cout << "No patient has been addmitted yet\n";
		break;
	}
	else {
	cout << "Enter the number of Days patient has been addmitted for: \n=========================";
    cin >> Addmited_For;
 	cout << "Enter patient ID: ";
 	cin >> patient[total_patient].id;
 	cout << "Enter illness: ";
 	cin >> patient[total_patient].illness;
 	
		for (int i = 0; i < total_patient; i++){
			cout << "The Patient " << patient[i].name << endl << "ID: " << patient[i].id << endl << "Addmitted for " << Addmited_For << " days\n ";
		}
	}
	
	
 }

else if (user_response == 3){
 	cout << "Enter illness: ";
 	cin >> patient[total_patient].illness;
 	cout << "Enter the number of days addmited";
 	cin >> Addmited_For ;
 	cout << "This Sums up your bill to " << Addmited_For * 1000;
 }
 else if (user_response == 4){
	cout << "You have exited the program. Thank you for using it\n";
	break;
 }
 else {
 cout << "Invalid response. Please try again.\n";
 }
 
}
total_patient++;

}

