#include <iostream>
using namespace std;

int powOfTwo(int num)
{
    int n = num - 1;
    if (num & n)
    {
        cout << "It is not power of 2";
    }
    else
    {
        cout << "It is power of 2";
    }
}

int main()
{
    powOfTwo(16);
    cout << "\n";
    powOfTwo(3);
    return 0;
}