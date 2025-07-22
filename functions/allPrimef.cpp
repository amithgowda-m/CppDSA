#include <iostream>
using namespace std;

bool isPrime(int x)
{
    bool r = true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void allPrimes(int n){
    for(int i =2;i<=n;i++){
        if (isPrime(i)){
            cout<<i;
        }
        cout<<" ";
        
    }
}

int main(){
    allPrimes(10);
}