#include <iostream>
#include <vector>
using namespace std;

long long catalanRec(int n){
    if(n==0||n==1) return 1;
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += catalanRec(i) * catalanRec(n-i-1);
    }
    return ans;
}

long long catalanMem(int n, vector<long long> &dp){
    if(n==0 || n==1) return 1;
    if(dp[n] != -1) return dp[n];

    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += catalanMem(i,dp) * catalanMem(n-i-1,dp);
    }
    return dp[n] = ans;
}

long long catalanTab(int n) {
    if (n <= 1) return 1;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main(){
    int n=10;
    vector<long long> dp(n+1,-1);

    cout << "Recursive: ";
    for(int i=0;i<n;i++) cout << catalanRec(i) << " ";
    cout << "\nCatalan(" << n << ") = " << catalanRec(n) << endl;

    cout << "\nMemoized: ";
    for(int i=0;i<n;i++) cout << catalanMem(i,dp) << " ";
    cout << "\nCatalan(" << n << ") = " << catalanMem(n,dp) << endl;

    cout << "\nTabulation: ";
    for(int i=0;i<n;i++) cout << catalanTab(i) << " ";
    cout << "\nCatalan(" << n << ") = " << catalanTab(n) << endl;

    return 0;
}
