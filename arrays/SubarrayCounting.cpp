//subarray means continous subsets but subsequence means all subsets
// number of subarrays is there are n elements means n(s)=n+(n-1)+(n-2)+..1; == (n)(n+1)/2
// to take subaray we need starting point(ie staring element/index) and ending point(last elemen/index)

#include <iostream>
using namespace std;

void printSubarray(int arr[],int n){//O(ncube)
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // cout<<"("<<start<<","<<end<<")";//this will print subarray index
            // cout<<",";
            for (int i = start; i <= end; i++)
            {
                cout<<arr[i];
            }
            cout<<", ";
        }
        cout<<endl;
        
    }
    
}
int main(){
    int n =5;
    int arr[n]={1,2,3,4,5};
    printSubarray(arr,n);

     
}