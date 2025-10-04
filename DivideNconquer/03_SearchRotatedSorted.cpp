#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int si, int ei, int tar){
    if(si>ei){
        return -1;
    }
    int mid = si+ (ei-si)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[si] <= arr[mid]){//l1
        if(arr[si]<= tar && tar  < arr[mid]){
            //left
            return search(arr,si,mid-1,tar);
        }
        else{
            //right helf
            return search(arr,mid+1,ei,tar);
        }
    }else{
        //l2
        if(arr[mid]<=tar && tar <= arr[ei]){
            //right hald
            return search(arr,mid+1,ei,tar );
        }
        else{
            //left half
            return search(arr,si,mid-1,tar);
        }
    }
}

//any one call will be executed

int main(){
    int arr[9]= {4,5,6,7,8,9,1,2,3};//array should be roated sorted
    int si =0;
    int ei = 8;
    int tar =7;
    cout<<search(arr,si,ei,tar);
    return 0;
}