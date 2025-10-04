#include <iostream>
using namespace std;

long factorial(int a) {
    long fact = 1;
    for (int i = 1; i <= a; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    long result = factorial(9);
    cout << result;
    return 0;
}
