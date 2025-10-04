#include <iostream>
#include <string.h>
using namespace std;

// Variables declared as static in a function are created and initialised once for the life time of the program
// static variables in a class are created and initialised once they are share by all the objects of the class
// static object remain in memory until program is closed

void counter()
{
    static int count = 0; // it exits in life time and changes happens to its previous value
    count++;
    cout << count << "\n";
}

class Example{
public:
    Example(){
        cout<<"constructor \n";
    }

    ~Example(){
        cout<<"Destructor\n";
    }
};


class Statics
{
public:           // static variable can be declared only inside a class
    static int x; // static variabble cant be initioalized inside a class
    // const variable can be initialised inside a class
};

// Initialize static member outside the class
int Statics::x = 0;

int main()
{
    Statics s1;
    Statics s2;
    Statics s3;

    int a = 0;
    if (a==0)
    {
        static Example eg1;
    }
    
    cout<<"code ending..\n";

    cout << s1.x++ << endl;
    cout << s2.x++ << endl;
    cout << s3.x++ << endl;
    counter();
    counter(); /// this will not run because it is static
    return 0;//here destructor prints last that indicated static function is long lived one
}