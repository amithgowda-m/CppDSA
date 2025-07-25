#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};  
    sort(arr,arr+8);//sort in ascending order

    
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    sort(arr,arr+8,greater<int>());//sort in decending order
    cout<<"\n";
     for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}