#include<iostream>
#include<vector>
using namespace std;

int fiboDP(int n,vector<int>& fibDp){//memoization dp O(n)
    if(n==0 || n==1){
        return n;
    }
    if(fibDp[n]!=-1){
        return fibDp[n];
    }
    fibDp[n] = fiboDP(n-1,fibDp)+fiboDP(n-2,fibDp);
    return fibDp[n];
}

int dpFib(int n){//tabulation dp O(n) --> in most of the cases tabulation method is more optimmized than memoization
    vector<int> arDp(n+1,0);
    arDp[1]=1;
    for(int i =2;i<=n;i++){
        arDp[i]=arDp[i-1]+arDp[i-2];
    }
    return arDp[n];
}

int main(){
    int n = 6;
    vector<int> fib(n+1,-1);
    cout<<fiboDP(n,fib)<<endl;
     cout<<dpFib(n)<<endl;
    return 0;
}