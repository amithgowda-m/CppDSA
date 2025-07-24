#include <iostream>
using namespace std;

void InsertionSort(int arr[],int n){//pick an element from unsortedd part and place it correctly in sorrted part
    for (int i = 0; i < n; i++){
        int curr = arr[i];
        int prev = i-1;
        
        while (prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }  
}

int main(){
    int arr[]={4,5,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    InsertionSort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i];
    }
    return 0;
}