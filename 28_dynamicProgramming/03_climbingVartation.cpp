#include <iostream>
#include <vector>

long long countWays(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;

    long long prev3 = 1; //3-3
    long long prev2 = 1; //3-2
    long long prev1 = 2; //3-1
    long long current = 0;

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2 + prev3;
    
        prev3 = prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n = 4; 
    std::cout << "Ways to reach stair " << n << ": " << countWays(n) << std::endl;
    return 0;
}