#include <iostream>
using namespace std;

bool sorted(int arr[],int n,int i){
     if(i==n-1){//base case
        return true;
     }
     if(arr[i]>arr[i+1]){
        return false;
     }
     return sorted(arr,n,i+1);  
}

int main(){
    int arr1[5]= {1,2,3,4,5};
    int arr2[5]={5,2,3,1,2};
    bool res = sorted(arr1, sizeof(arr1)/sizeof(arr1[0]),0);//true sorted

    cout<<res;
    return 0;
}