#include <iostream>
using namespace std;
//struct patient {
//	
//	string name , gender , illness  ;
//	int age , id  ;
//};
int main (){
 string name , illness ;
 char gender ;
 int age , id , user_response , Addmited_For ;

 cout << " ===== HOSPITAL MANAGEMENT SYSTEM ===== \n\n1. Add Patient \n2. View Patients\n3. Generate Bill\n4. Exit \n" ;
 
 cin >> user_response;
 if (user_response == 1){
 	cout << "Enter patient name: ";
 	cin >> name;
 	cout << "Enter patient age: ";
 	cin >> age;
 	cout << "Enter patient gender (press M or F ): ";
 	cin >> gender;
 	cout << "Enter patient ID: ";
 	cin >> id;
 	cout << "Enter illness: ";
 	cin >> illness;
 	
 }
 else  if (user_response == 2){
    cout << "Enter the number of Days patient has been addmitted";
    cin << Addmited_for;
 	cout << "Enter patient ID: ";
 	cin >> id;
 	cout << "Enter illness: ";
 	cin >> illness;
 	Cout << "The Patient " << name << "has been addmitted for " << Addmited_for << " days";
 }
;
else  if (user_response == 3){
 	cout << "Enter illness";
 	cin >> illness ;
 	cout << "Enter the number of days addmited";
 	cin >> Addmited_for ;
 	Cout << "This Sums up your bill to " << Addmited_for * 1000;
 	

 }
}