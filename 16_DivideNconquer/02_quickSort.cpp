#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[] ,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int si,int ei){
    int i =si-1;
    int pivot =arr[ei];
    for (int j = si; j < ei; j++){// hrere j from 0 to 4
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);//swap arr[2] with arr[5] So pivot 4 goes to index 2:
    //pivotIdx =i
    return i;
//     Left side [3, 2] (all <= pivot)
// Right side [5, 6, 7] (all > pivot)
// And the pivot 4 is locked in its correct final place.
}

void quickSort(int arr[],int si, int ei){
    if (si>=ei){
        return;
    }
    int  pivotIdx = partition(arr,si,ei);
    quickSort(arr,si,pivotIdx-1);//left helf Call quickSort on left [3, 2] → sorts into [2, 3].
    quickSort(arr,pivotIdx+1,ei);//right halfCall quickSort on right [5, 6, 7] → already sorted.
}

int main(){
    int arr[6]={6,3,7,5,2,4};
    int n=6;

    quickSort(arr,0,n-1);
    printArr(arr,n);
    return 0 ;
}


// QuickSort works by picking a pivot (in your code, arr[ei] = last element of the subarray).
// Then it rearranges the subarray so that:
// all numbers smaller than or equal to pivot go to the left,
// all numbers greater than pivot go to the right.
// After that, you recursively sort the left and right parts.
// j is the scout: it runs through every element.
// i is the boundary: it marks the “end” of the section of numbers ≤ pivot.
// Whenever j finds something ≤ pivot, we extend that boundary (i++) and swap it into place.
// By the end, everything to the left of i is ≤ pivot. Then you swap pivot into position i+1.