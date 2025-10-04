#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int a){
    int Prime =1;
    for (int i = 2; i < sqrt(a); i++)// we can do till i<a but this is efficient algorithm
    {
        if (a%i == 0)
        {
            Prime = 0;
        }    
    }
    if (Prime)
        {
            cout<<a<<" is Prime\n";
        }
        else{
            cout<<a<<" is not Prime \n";
        }
    return 0;
    
}
int main(){
    isPrime(7);
    return 0;
}