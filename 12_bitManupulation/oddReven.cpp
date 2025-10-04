#include <iostream>
using namespace std;

void oddOrEven(int num){
    if (!(num & 1))// here 1 is called as bitmask
    {
        cout<<"even\n";
    }
    else{
        cout<<"Odd\n";
    }
}

int main(){
    oddOrEven(5);
    oddOrEven(8);
    return 0;

}