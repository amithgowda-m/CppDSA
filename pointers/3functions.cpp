#include <iostream>
using namespace std;

void changeAvalue(int a){//this arguement is a copy of the parameter sent by main function
    a= 30;          //it will change inside function only as it is call by value
    cout<<"a from call by value : "<<a;
}

void changeAReference(int *a){
    *a = 27;
    cout<<"\na from call by reference : "<<*a;
}

void changeArefvari(int &refa){//reference variable means talking about same memory location
    refa = 89;
    cout<<"\n from refvar : "<<refa;
}

int main(){
    int a =2;
    int &b = a;//whenever reference variable is created we should initialize that first
    changeAvalue(a);
    cout<<"\na in main after passing to call by value function is : "<<a;

    changeAReference(&a);
    cout<<"\na in main after passing to call by reference function is : "<<a;

    changeArefvari(b);//as b is reference variable of a ( a du innod name is b)
    cout<<"\na in main after passing to call by reference var function is : "<<a;


    return 0;
}

