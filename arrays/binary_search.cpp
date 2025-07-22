#include <iostream>
using namespace std;

void BinarySearch(int arr[],int n,int key){
    int first =0,last = n-1,mid=(first+last)/2;
    int found = 0;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid]<key){
            first = mid+1;
        }
        else if(arr[mid]==key){
            cout<<key<<" Found at location "<<mid+1;
            found =1;
            break;
        }
        else{
            last=mid-1;
        }
    }
    if(found==0){
        cout<<"Not found!";
    }
}
int main(){
    int arr[30],n,key;
    cout<<"Enter the number of elements : ";
    cin>>n;

    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++){
        cin >> arr[i];
        }
    cout<<"Enter a number to search ";
    cin>>key;
    BinarySearch(arr,n,key);
    return 0;
}