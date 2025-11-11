#include <iostream>
using namespace std;

// int reverseArr(int arr[],int n){
//     int rArr[n];
//     for (int i = n-1; i >=0; i--){
//         rArr[n-i-1]=arr[i]; 
//     }
//     cout<<"The reversed array is : ";
//     for (int i = 0; i <n; i++){
//         cout<<rArr[i];
//     }
// }

int main(){
    int arr[]={1,2,3,4};
    int n = 4;
    // reverseArr(arr,n);//from this space complexity is O(n)

    // to make more efficient algorithm is O(1)

    int start = 0,end = n-1,temp;
    while(start<end){
        temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    cout<<"The reversed array is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
}