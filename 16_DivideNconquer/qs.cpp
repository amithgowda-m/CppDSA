#include <iostream>
#include <string>
using namespace std;

void printArr(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(string arr[], int si, int ei) {
    // FIX: Change 'int' to 'string' to match the array type
    string pivot = arr[si]; 
    
    int i = si; 

    for (int j = si + 1; j <= ei; j++) {
        // Strings compare lexicographically (A < B)
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[si], arr[i]);
    return i; 
}

void quickSort(string arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    
    int pivotIdx = partition(arr, si, ei);
    
    quickSort(arr, si, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, ei);
}

int main() {
    // FIX: Use double quotes for string literals
    string arr[10] = {"A","D","S","O","R","P","T","I","V","E"};
    int n = 10;

    quickSort(arr, 0, n - 1);
    printArr(arr, n);
    
    return 0;
}