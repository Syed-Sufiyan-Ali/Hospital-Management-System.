#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Login
{
private:
    string username;
    string password;

public:
    Login()
    {
        ifstream file("userpass.txt");

        if (file.is_open())
        {
            string line;

            getline(file, line);

            stringstream ss(line);

            getline(ss, username, '|');
            getline(ss, password);

            file.close();
        }
    }

    bool authenticate(string input_username, string input_password)
    {
        if (input_username == username &&
            input_password == password)
        {
            return true;
        }

        return false;
    }
};
