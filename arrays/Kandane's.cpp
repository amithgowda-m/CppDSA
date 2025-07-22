#include <iostream>
using namespace std;

void Kadane(int arr[],int n){
    int curSum=0;
    int maxSum=INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        curSum+=arr[i];
        maxSum=max(maxSum,curSum);
        if (curSum<0)
        {
            curSum=0;
        }
        
    }
    cout<<"Maximum subarray sum is : "<<maxSum;
    
}

int main(){
     int arr[6]={2,-3,6,-5,4,2};
     int n =sizeof(arr)/sizeof(int);
     Kadane(arr,n);
     return 0;
}