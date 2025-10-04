#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"ENter a number to get its multiplication table: ";
    cin>>n;

    for (int i = 1; i <=10; i++)
    {
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }
    
}