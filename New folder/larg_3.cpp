#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout<<"Enter a  : "<<endl;
    cin>> a;
    cout<<"Enter b  : "<<endl;
    cin>> b;
    cout<<"Enter c  : "<<endl;
    cin>> c;

    if(a>=b && b>=c){
        cout<<"a is larger";
    }
    else if(b>=a && b>=c){
        cout<<"b is larger";
    }
    else{
        cout<<"c is larger";
    }
}