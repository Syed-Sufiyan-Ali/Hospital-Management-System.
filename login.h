#include <iostream>
using namespace std;
class Login {
 private :
    string username = "ManageSystem";
    string password = "password123";
 public :
    bool authenticate(string U , string P) {
       return (U == username && P == password);

    }

};