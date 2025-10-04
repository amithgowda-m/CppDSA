#include <iostream>
using namespace std;

int linearSearch(int arr[],int n,int key){
    // int i;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
    
    
    
}

int main(){
    int arr[30],n,key,found=0;
    cout<<"Enter the number of elements : ";
    cin>>n;

    cout<<"Enter "<<n<<" elements"<<endl;

    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    cout<<"\nEnter the value to search : "<<endl;
    cin>>key;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==key){
            found =1;
            cout<<"\nThe value is found at index "<<i;
        }
       

    }
    if (found=0)
    {
        cout<<"Not found";
    }

    int result = linearSearch(arr,n,key);
    if (result!=-1)
    {
        cout<<"\n from function The value is found at inddex : "<<result;
    }
    else{
        cout<<"Value not found";
    }
    
    

    
    return 0;
    
}