#include <iostream>
using namespace std;


// Intuition
// To trap water at any index in the elevation map, there must be taller bars on both its left and right sides. The water that can be stored at each position is determined by the height of the shorter of the two boundaries (left and right), minus the height of the current bar.
// We compute the trapped water at each index as: min(leftMax, rightMax) - height[i], if this value is positive.
// The total trapped water is the sum of water stored at all valid indices.
// If either side lacks a boundary, no water can be trapped at that position.

void waterTrapped(int *heights,int n){//O(n)
    int rightMax[100],leftMax[100];
    // int mini[100];
    rightMax[n-1]=heights[n-1];
    leftMax[0]=heights[0];     

    for (int i = 1; i < n; i++){
        leftMax[i]=max(leftMax[i-1],heights[i-1]);
    }
    for (int i = n-2; i >=0 ; i--){
        rightMax[i]=max(rightMax[i+1],heights[i+1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    // mini[i]=min(leftMax[i],rightMax[i]);//min - height = waterr trapperrd
    // }
    int waterTrapped=0;
    int curWater=0;
    for (int i = 0; i < n; i++){//O(n)
        curWater=min(leftMax[i],rightMax[i])-heights[i];
        if (curWater>0){
            waterTrapped+=curWater;
        }
    }
    cout<<waterTrapped;
}

int main(){
    int heights[7]={4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);
    waterTrapped(heights,n);
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxWater(vector<int>& arr) {
//     int res = 0;

//     // For every element of the array
//     for (int i = 1; i < arr.size() - 1; i++) {

//         // Find the maximum element on its left
//         int left = arr[i];
//         for (int j = 0; j < i; j++)
//             left = max(left, arr[j]);

//         // Find the maximum element on its right
//         int right = arr[i];
//         for (int j = i + 1; j < arr.size(); j++)
//             right = max(right, arr[j]);

//         // Update the maximum water
//         res += (min(left, right) - arr[i]);
//     }

//     return res;
// }

// int main() {
//     vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
//     cout << maxWater(arr);
//     return 0;
// }