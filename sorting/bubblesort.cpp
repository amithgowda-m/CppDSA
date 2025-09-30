#include <iostream>
using namespace std;

void asBubbleSort(int *arr,int n){//large elements come to end by sswapping with adjacents
    int temp;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n-i; j++){
            if (arr[j]>arr[j+1])//arr[j]>arr[j+1]
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }   
        }   
    }   
} 
void decBubbleSort(int *arr,int n){//large elements come to end by sswapping with adjacents
    int temp;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n-i; j++){
            if (arr[j]<arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }   
        }   
    }   
} 

int main(){
    int arr[]={4,5,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    asBubbleSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    cout<<"DEscending: ";
    decBubbleSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    return 0;
}