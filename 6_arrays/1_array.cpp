#include <iostream>
using namespace std;

int main(){
    int marks[5];
    cout<<marks[20];
    cout<<"Enter the elements : ";
    for (int i = 0; i < 5; i++)
    {
        cin>>marks[i];
    }
    cout<<"\n";
    for (int i = 4; i>=0; i--)
    {
        cout<<marks[i];
    }
    cout<<"\n";
    cout<<sizeof(marks); //sizeof array by sze of int give size or array
    return 0;
}