#include <iostream>
using namespace std;

int main(){
    int arr[30],n,max =0,min=0;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"\nEnter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(int i =1 ;i<n;i++){
        if (arr[max]<=arr[i])
        {
            max =i;
        }
        if (arr[min]>=arr[i])
        {
            min=i;
        }
        
        
    }
    cout<<"The maximum is : "<<arr[max];
    cout<<"\nThe minimum is : "<<arr[min];
    return 0;

}