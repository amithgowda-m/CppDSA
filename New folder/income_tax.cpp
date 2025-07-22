#include <iostream>
using namespace std;

int main(){
    int income;
    float tax;
    cout<<"Enter your income in terms of Lakhs :"<<endl;
    cin>>income;

    if(income<5){
        tax = 0;

    }
    else if(income >=5 && income<10){
        tax = 0.2*income;
    }
    else{
         tax =0.3*income;
    }
    cout<<"Tax = "<<(tax*100000)<<endl;
    return 0;
}   