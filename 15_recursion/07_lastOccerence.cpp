#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector <int> arr, int i , int target){
    if(i==arr.size()){//when traversal is completed then the target is not found in that vecotr
        //i is the current index. When it reaches the end of the array, there are no more elements to check.
        return -1;
    }
    int idxFound = lastOccurence(arr,i+1,target);//
    if (idxFound ==-1 && arr[i]==target){//If no later occurrence is found (idxFound == -1), it finally returns i = 0.
            return i;
        }
    return idxFound;
}

//lastoccurenc logic is
//i=0 → call i=1
// i=1 → call i=2
// i=2 → call i=3
// i=3 → call i=4
// i=4 → call i=5
// i=5 → base case → return -1
//so if target is at index 0 Instead, it first calls lastOccurence(arr, 1, target) to check the rest of the array. it will go beyond it and then unwind and gives the answer
//unwind
// step 2: Unwinding
// i=4 → idxFound = -1, arr[4] = 5 → not target → return -1
// i=3 → idxFound = -1, arr[3] = 4 → not target → return -1
// i=2 → idxFound = -1, arr[2] = 3 → current element = target, idxFound = -1 → return 2 
// i=1 → idxFound = 2 → return 2
// i=0 → idxFound = 2 → return 2


int lastxOccurence(const vector<int>& arr, int i, int target) {
    if (i == arr.size()) return -1; // base case
    int restIndex = lastxOccurence(arr, i + 1, target); // check later elements
    if (restIndex != -1) {
        return restIndex; // a later occurrence exists, use it
    }
    if (arr[i] == target) {
        return i; // no later occurrence, this is the last one
    }
    return -1; // not found
}

int main(){
    vector <int> arr = {1,2,3,4,5,1,4};
    int res = lastOccurence(arr,0,1);
    cout<<res<<"\n";
    cout<<lastxOccurence(arr,0,1);
    return 0;
}