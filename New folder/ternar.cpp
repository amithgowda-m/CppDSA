#include <iostream>
using namespace std;

int main(){
    bool isAdult;
    int age;
    cout<<"Enter your age : ";
    cin >> age;

    // if(age>=18){
    //      isAdult = true;
    // }
    // else{
    //     isAdult= false;
    // }

    isAdult =(age >=19)? "Even": "odd";
}