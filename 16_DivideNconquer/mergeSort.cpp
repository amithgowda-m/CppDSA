#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[],int si , int mid, int ei){//O(n) Purpose: Merge two sorted subarrays into a single sorted array.
    vector<int> temp;
    int i =si;//left half
    int j = mid+1;//right half

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
        }
    }
    //when one array completes;
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }
    //vecot -> org arr
    for(int idx= si , x=0; idx<=ei;idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei){//O(nlogn)
//Purpose: Recursively divide the array into smaller parts until each part has 1 element, then merge them in sorted order.
    if (si>=ei){//Base case: If start index >= end index, the array has 1 or 0 elements → already sorted.
        return;
    }
    int mid = (si+ei)/2;//si+(ei-si)/2  

    mergeSort(arr,si,mid);//left half
    mergeSort(arr,mid+1,ei);//right halk
    merge(arr,si,mid,ei);//conquer
}

void printArr(int arr[],int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6]={6,3,7,5,2,4};
    int n =6;
   
    mergeSort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}
