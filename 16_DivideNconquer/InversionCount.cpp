// // Given an array of integers. Find the Inversion Count in the array. (HARD) 
// // Inversion Count: For an array, inversion count indicates how far (or close) the array is 
// // from being sorted. If the array is already sorted then the inversion count is 0. If an array 
// // is sorted in the reverse order then the inversion count is the maximum. 
// // Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// Sample Input 1 : N = 5, arr[ ] = {2, 4, 1, 3, 5} 
// Sample Output 1 : 3, because it has 3 inversions - (2, 1), (4, 1), (4, 3). 
// Sample Input 2 : N = 5, arr[ ] = {2, 3, 4, 5, 6} 
// Sample Output 2 : 0, because the array is already sorted 
// Sample Input 3 : N = 3, arr[] = {5, 5, 5} 
// Sample Output 3 : 0, because all the elements of the array are the same & already in a 
// sorted manner. 

#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    
    for(int i=0;i<n1;i++) left[i] = arr[l + i];
    for(int j=0;j<n2;j++) right[j] = arr[m + 1 + j];

    int i=0, j=0, k=l;
    int invCount = 0;

    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i); // all remaining elements in left[] are inversions
        }
    }

    while(i<n1) arr[k++] = left[i++];
    while(j<n2) arr[k++] = right[j++];

    return invCount;
}

int mergeSortAndCount(int arr[], int l, int r) {
    int invCount = 0;
    if(l < r) {
        int m = l + (r-l)/2;
        invCount += mergeSortAndCount(arr, l, m);
        invCount += mergeSortAndCount(arr, m+1, r);
        invCount += mergeAndCount(arr, l, m, r);
    }
    return invCount;
}

int main() {
    int arr[] = {2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << mergeSortAndCount(arr, 0, n-1) << endl; // Output: 3
}
