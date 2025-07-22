#include <iostream>
using namespace std;

// Function to modify the first element of the array using array notation
void func(int arr[]) {
    *(arr) = 1000; // Same as arr[0] = 1000
}

// Function to modify the first element of the array using pointer notation
void func2(int *ptr) {
    ptr[0] = 1000; // Also changes arr[0] in main
}

// Function to print the size of the array parameter
void prinArr(int nums[]) {
    // This line doesn't give size of array in main!
    cout <<"\n"<<sizeof(sizeof(nums) )  ; // This prints size of pointer (usually 4 or 8 bytes), NOT the array
}

int main() {
    int a = 5;
    // int *ptr = &a;
    // cout << ptr << endl;  // prints address of `a`

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int); // Proper way to get array size (5)
 
    // func(arr);     // changes arr[0] to 1000
    // func2(arr);    // again sets arr[0] to 1000
    // cout << *(arr); // prints arr[0] => 1000

    prinArr(arr);  // prints size of pointer, NOT actual array size (typically 8 on 64-bit systems)
    
    return 0; 
}
