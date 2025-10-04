#include <iostream>
using namespace std;

class User
{
    int id;
    int password;//commonly it is a string

public:
    string username;

    User(int id)
    {
        cout << "\n Calling parameterized constructor\n";
        this->id = id;   // *(this).password = 
    }
    void setPass(int password)
    {
        this->password = password;
    }
    int getPass()
    {
        return password;
    }
};

int main()
{
    User U1(1234);
    U1.setPass(123);
    cout << "Password is : " << U1.getPass();
    return 0;
}