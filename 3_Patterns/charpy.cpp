#include <iostream>
using namespace std;
// A
// BC
// DEFF
// GHIJK
int main(){
    int n;
    char ch ='A';
    cout<<"Enter number of lines: ";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        for (char j = 1; j <= i; j++)
        {
            cout<<ch++;
            // ch++;
        }
        cout<<endl;
        
    }
    
}