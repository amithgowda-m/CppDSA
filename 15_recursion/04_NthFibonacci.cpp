#include <iostream>
using namespace std;

int NthFibonacci(int n){
    if (n==1 || n==2 || n==3){
        return 1;
    }
    else{
        return NthFibonacci(n-1)+NthFibonacci(n-2);//at once one the left one will we executed untill that returns a value then next after +
    }
}

int main(){
    int res = NthFibonacci(5);
    cout<<res;
    return 0;
}