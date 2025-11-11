#include <iostream>
using namespace std;
//OOPS : class, object ,Member functions and properties
//in cpp there is one class called string whoose objects we can do
//string str ="hello"//here str is object and its clas and type is sting
#include <string>

int main(){
    string str = "Hello";
    getline(cin,str,'$');
    cout<<str<<endl;
    cout<<str[0];
    str="World";
    cout<<str;
    return 0;
}