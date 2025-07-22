#include <iostream>
using namespace std;

int main(){
    int n, lastDig,sum =0;

    cout<<"Enter a number : ";
    cin>> n;

    while (n>0)
    {
        lastDig = n%10;
        n = n/10;
        if (lastDig%2!=0)
        {
            sum+= lastDig;
        }
            /* code */
        }
        
    cout<<"The sum of digits : "<<sum<<endl;
    return 0;
    
}