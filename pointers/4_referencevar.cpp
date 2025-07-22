#include <iostream>
using namespace std;

int main(){
    int a =10;
    int &b =a;
    b= 90;//b is refference variable that means b also a here
    cout<<"A is : "<<a;
    cout<<"\nB is : "<<b;
}