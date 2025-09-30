#include <iostream>
using namespace std;
// this is important question
int countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int lastDig = num & 1;
        count += lastDig;
        num = num >> 1;
    }
    cout << count;
    return count;
}

int main()
{
    countSetBits(7);
    return 0;
}
