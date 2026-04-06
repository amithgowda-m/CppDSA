#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    int greatest = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    cout << "Greatest of " << a << ", " << b << ", " << c << " is: " << greatest << endl;
    return 0;
}
