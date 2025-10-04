#include <iostream>
using namespace std;

int sum(int n){//O(n)
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

int main(){
    int res = sum(10);;
    cout<<res;
    return 0;
}