#include <iostream>
using namespace std;

//pick the smallest from unsorted and put in the beginning

void SelectionSort(int *arr,int n){
    int temp;
    for (int i = 0; i < n; i++){
        int min =i;
        for (int j = i+1; j < n; j++){
            if (arr[j]<arr[min]){
                min =j;
            }
            if (min!=i){
                temp = arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }           
        }   
    }
}
int main(){
    int arr[]={4,5,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
   
    return 0;
}