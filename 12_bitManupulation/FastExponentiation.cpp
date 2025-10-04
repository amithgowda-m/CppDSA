#include <iostream>
using namespace std;

int fastEx(int base, int pow)
{
    int ans = 1;
    while (pow > 0) // here i did mistake i took base for the same condition which is wrong as we want to take binary of power
    {
        int lastBit = pow & 1;
        if (lastBit)
        {
            ans = ans * base;
        }
        base = base * base;
        pow = pow>>1;// here i took base instead of power that is a mistake
    }
    return ans;
}

int main()
{
    cout << fastEx(3, 5);
    return 0;
}