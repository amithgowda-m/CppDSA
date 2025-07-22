#include <iostream>
using namespace std;

int main(){
    int n, lastDig,sum =0;

    cout<<"Enter a number : ";
    cin>> n;

    while (n>0)
    {
        lastDig = n%10;
        cout<<lastDig<<"";//to print digits of a number in reverse order   // sum+= lastDig; to just sum those digits
        n = n/10;
        sum+=lastDig;
    }
    // cout<<"\n";this line doing batmez
    cout << "\nThe sum of digits: " << sum << endl;
    return 0;
    
}