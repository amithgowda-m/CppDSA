#include <iostream>
using namespace std;

void Sumon3(int *arr,int n){
    int curSum;
    int MM = INT32_MIN;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {   cout<<"( ";
            curSum=0;
            for (int i = start; i <=end ; i++)
            {
                cout<<*(arr+i);
                cout<<" ";
                curSum+=*(arr+i);
            }
            cout<<" ),";
            MM= max(curSum,MM);

            
        }
        cout<<endl;
        
    }
    cout<<"Max : "<<MM;
    
}

int main(){
    int arr[5]={50,40,30,20,10};
    int n = sizeof(arr)/sizeof(int);
    Sumon3(arr,n);

    return 0;
}