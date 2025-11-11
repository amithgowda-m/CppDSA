#include <iostream>
using namespace std;

//  1
//  01
//  101
//  0101
//  10101

int main(){
    int n=0;
    cout<<"Enter the number of lines to print binary triangle: ";
    cin>>n;

    for(int i=1;i<=n;i++){// for each row printing
        int start;
        if(i%2!=0){
            start=1;
        }
        else{
            start = 0;
        }
        for(int j=1;j<=i;j++){
            cout<<start;
            start=1-start;//alt zeros and ones so we do this
        }
        cout<<endl;
    }
    return 0;
}