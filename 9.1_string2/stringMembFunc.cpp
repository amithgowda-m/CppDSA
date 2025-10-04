#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "Amith Gowda";
    cout<<str.length();   
    cout<<"\n";
    cout<<str.substr(1,5);
    cout<<"\n";
    cout<<str.at(3);
    cout<<"\n";
    cout<<str.find("a",3);//3 tells starting index from where it should find
    cout<<"\n";
    cout<<str.find("Gowda");//if it not exist it give garbage number that equal to -1
    return 0;
}