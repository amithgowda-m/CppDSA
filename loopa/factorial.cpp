#include <iostream>
using namespace std;

int main(){
    int n,facn=1;
    cout<<"Enter a number to find its fatorial : ";
    cin>>n;
    for(int i =n; i>0;i--){
        facn = i*facn;


    }
    cout<<n<<"factorial is :"<<facn<<endl;
    
    return 0;
}

