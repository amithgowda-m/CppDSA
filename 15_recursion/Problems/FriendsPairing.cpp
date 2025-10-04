#include <iostream>
using namespace std;

int friendPair(int n){
    // if(n==1){
    //     return 1;
    // }
    // if(n==2){
    //     return 2;
    // }
    // //first friend single
    // int single = friendPair(n-1);
    
    // // first paired
    // int pair = (n-1)*(friendPair(n-2));
    
    if(n==1||n==2){
        return n;
    }
    return friendPair(n-1)+(n-1)*(friendPair(n-2));

}

int main(){
    int res = friendPair(3);
    cout<<res;
    return 0;
}