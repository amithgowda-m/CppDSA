#include <iostream>
#include <math.h>

using namespace std;

int PrintPrime(int a)
{
    cout << "Printing all primes from 2 to" << a<<"\n";
    for (int i = 2; i <= a; i++)
    {
        bool isPrimee = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrimee = false;
                break;
            }
        }
        if (isPrimee)
        {
            cout <<i;
        }
        cout<<" ";
    }
    return 0;
}
int main()
{
    PrintPrime(7);
    return 0;
}