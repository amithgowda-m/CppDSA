#include <iostream>
#include<math.h>
using namespace std;

void bi2Dec(int n){
    int result = 0;
    int lastDig=0;
    int pos=0;

    while(n>0){
        lastDig = n%10;
        result+= lastDig*pow(2,pos);
        n=n/10;
        pos++;
    }
    cout<<"Decimal is: "<<result;
}

int main(){
    int n =1011;
    bi2Dec(n);
    return 0;
}