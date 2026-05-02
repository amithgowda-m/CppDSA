#include <iostream>
#include<vector>
using namespace std;

int mcmRec(vector<int> arr,int i,int j){
    if(i==j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k =i;k<j;k++){
        int cost1 = mcmRec(arr,i,k);
        int cost2= mcmRec(arr,k+1,j);

        int currCost = cost1+cost2+ (arr[i-1]*arr[k]*arr[j]);

        ans= min(ans,currCost);
          
    }
    return ans;
}

int mcmMem(vector<int> arr,int i,int j,vector<vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k =i;k<j;k++){
        int cost1 = mcmMem(arr,i,k,dp);
        int cost2= mcmMem(arr,k+1,j,dp);

        int currCost = cost1+cost2+ (arr[i-1]*arr[k]*arr[j]);

        ans= min(ans,currCost);
          
    }
    return dp[i][j]=ans;
}

int main(){
    vector<int> arr={1,2,3,4,3};
    int n = arr.size();
    cout<<mcmRec(arr,1,n-1)<<endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<mcmMem(arr,1,n-1,dp);
    return 0;
}