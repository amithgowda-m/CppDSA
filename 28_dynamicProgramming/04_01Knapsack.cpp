#include<iostream>
#include<vector>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int W,int n){
    if(n==0 || W==0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <=W){
        int ans1 = knapsackRec(val,wt,W-itemWt,n-1)+itemVal;//what if we made a mistabe by including this because there may be someother element which has more value than this so we are taking max of including and excluding them

        int ans2 = knapsackRec(val,wt,W,n-1);//excluded

        return max(ans1,ans2);
    }else{
        return knapsackRec(val,wt,W,n-1);//exclude
    }
}

int knapsackMem(vector<int> val,vector<int> wt,int W,int n,vector<vector<int>> &dp){
    if(n==0||W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int itemWt = wt[n-1];//selecting the last wt in the vector
    int itemVal = val[n-1];

    if(itemWt<=W){
        int ans1 = knapsackMem(val,wt,W-itemWt,n-1,dp)+itemVal;

        int ans2 = knapsackMem(val,wt,W,n-1,dp);

        dp[n][W]= max(ans1,ans2);
    }else{
        dp[n][W]=knapsackMem(val,wt,W,n-1,dp);
    }
    return dp[n][W];

}

int knapsackTab(vector<int> val,vector<int> wt,int W,int n){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));//n=0 and w=0 we make dp ans as 0
    for(int i=1;i<=n;i++){//item array that is same as n
        for(int j =0 ;j<=W;j++){//from 0 to Weight of the knapsack for storing ans for all the possible combinations
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt<=j){
                dp[i][j] = max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][W];

}

int main(){
    vector<int> val = {15,14,10};
    vector<int> wt = {2,5,1};
    int W  = 4;
    int n = 3;
    cout<<knapsackRec(val,wt,W,n)<<endl;
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));//for knapsack memoization
    cout<<"Memoization ans: "<<knapsackMem(val,wt,W,n,dp)<<endl;
    cout<<"Tabulation ans: "<<knapsackTab(val,wt,W,n);
    return 0;
}