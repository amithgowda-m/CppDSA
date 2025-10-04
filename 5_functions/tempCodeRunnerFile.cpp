#include <iostream>
using namespace std;

void dec2bin(int a){
    int remainder =0;
    int result = 0;
    int pow =1;

    while (a>0)
    {
        remainder = a%2;
        result += remainder*pow;
        pow= pow*10;
        a =a/2;

    }
    cout<<result;
}

int main(){
    dec2bin(7);
    return 0;
}
