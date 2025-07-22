#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;

    cout << "Enter the first number : ";
    cin >> a;
    cout << "Enter the second number : ";
    cin >> b;

    int sum = a + b;
    int product = a * b;

    cout << "The sum is: " << sum << endl;
    cout << "The product is : " << product << endl;

    return 0;
}