#include <iostream>
using namespace std;

int main (){
    int n,sum=0;
    cout<<"Enter a number to check: ";
    cin>>n;
    int original = n;
    while (n>0)
    {
        int dig=n%10;
        sum= sum + dig*dig*dig;
        n= n/10;



    }

    if (sum == original)
    {
        cout<<original<<" is a armstrongg number"<<endl;
    }
    
    else{
        cout<<"Not an Armstrong number"<<endl;
    }
    
    
}