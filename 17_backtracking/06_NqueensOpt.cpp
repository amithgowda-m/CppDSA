#include <iostream>
using namespace std;

int solve(int n, int row, int cols, int d1, int d2) {
    if (row == n) return 1; // one valid arrangement found

    int count = 0;
    int available = ((1 << n) - 1) & ~(cols | d1 | d2); // bits where we can place a queen

    while (available) {
        int pos = available & -available; // isolate rightmost 1-bit (safe position)
        available -= pos; // remove that bit

        // Recurse with updated masks
        count += solve(n, row + 1,
                       cols | pos,
                       (d1 | pos) << 1,
                       (d2 | pos) >> 1);
    }
    return count;
}

int main() {
    int n = 8; // try with 8
    cout << "Total solutions for " << n << "-Queens: "
         << solve(n, 0, 0, 0, 0) << endl;
}
