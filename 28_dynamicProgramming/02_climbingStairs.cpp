#include<iostream>
#include<vector>
using namespace std;


int nWays(int n){//recursion approach
    if(n==0 || n==1){
        return 1;
    }
   
    return  nWays(n-1)+nWays(n-2);
}

int mWays(int n,vector<int> &ways){//memoization
    ways[0]=1;
    ways[1]=1;
    if(n==0 || n==1){
        return 1;
    }

    if(ways[n]!=-1){
        return ways[n];
    }

    ways[n] = mWays(n-1,ways)+ mWays(n-2,ways);
    return ways[n];
}

int tWays(int n){
    vector<int> ways(n+1);
    ways[0]=1;
    ways[1]=1;
    for(int i=2;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-2];
    }
    return ways[n];
}

int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
}

int climb3stairs(int n){
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}
int main(){
    int n = 4;
    cout<<nWays(n)<<endl;
    vector<int> ways(n+1,-1);
    cout<<"Memoization : "<<mWays(n,ways)<<endl;
    cout<<"Tabulation : "<<tWays(n)<<endl;
    cout<<"Tabulation 3stais : "<<climb3stairs(n)<<endl;
    return 0;
}

