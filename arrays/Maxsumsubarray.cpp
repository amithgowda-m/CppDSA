#include <iostream>//bruteforce approach
using namespace std;

void MaxSubArrSum(int arr[],int n){//o(ncube)
    int maxSum = INT32_MIN;
    for(int start =0;start<n;start++){
        for(int end=start;end<n;end++){
            int curSum=0;
            for (int i = start; i <= end; i++)
            {
                curSum+=*(arr+i);
                maxSum= max(maxSum,curSum);
            }
            cout<<endl;
        }
    }
    cout<<"Maximun subarray sum "<<maxSum;

}

void MaxSubSum(int arr[],int n){//time complexity o(nsquare)
    int maxSum=INT32_MIN;
    for(int start =0;start<n;start++){
        int curSum=0;
        for(int end=start;end<n;end++){
            curSum+=arr[end];
            maxSum=max(curSum,maxSum);
        }
    }
    cout<<"\n"<< maxSum;
}
void Kadane(int arr[],int n){//time complexity =o(n)
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
    cout<<"O(n) Maximum subarray sum is : "<<maxSum;
    
}
int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int n =sizeof(arr)/sizeof(int);
    cout<<"brute force O(n^3) : ";
    MaxSubArrSum(arr,n);
    cout<<endl;
    cout<<"Optimized brute force O(n^2) : ";
    MaxSubSum(arr,n);
    cout<<endl;
    Kadane(arr,n);
    return 0;
}