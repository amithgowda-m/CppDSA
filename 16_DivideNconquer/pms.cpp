#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){
    vector <int> temp ;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
        temp.push_back(arr[i++]);
    }
    else{
        temp.push_back(arr[j++]);
    }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    for (int i = si, x=0; i <= ei; i++){
        arr[i]=temp[x++];
    }
    
}

void mergeSort(int arr[],int si, int ei){
    if (si>=ei)
    {
        return;
    }
    
    int mid = si + (ei-si)/2;

    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

int main(){
    int arr[7]={2,5,2,1,4,3,9};
    mergeSort(arr,0,6);
    for(int i = 0; i<7;i++){
        cout<<arr[i]<<" ";
    } 
    return 0;
}