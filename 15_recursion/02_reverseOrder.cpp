#include <iostream>
using namespace std;

void reversePrint(int n) {
    if (n == 0) {   // base case
        return;
    }
    cout << n << " ";   // print current number
    reversePrint(n - 1); // recursive call
}

int main() {
    reversePrint(5);  // prints: 5 4 3 2 1
    return 0;
}
