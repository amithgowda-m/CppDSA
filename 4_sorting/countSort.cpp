#include <iostream>
using namespace std;

void countSort(int arr[], int n) {
    
    int freq[1000] = {0};  

    
    int minVal = INT32_MAX;
    int maxVal = INT32_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

   
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;  
    }

    
    int j = 0;
    for (int i = minVal; i <= maxVal; i++) {
        while (freq[i] > 0) {
            arr[j] = i;   
            j++;         
            freq[i]--;    
        }
    }
}

int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};  
    countSort(arr, 8);  

    
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
