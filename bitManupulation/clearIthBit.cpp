#include <iostream>
using namespace std;

int clearIthBit(int num , int i){
    int bitMask = ~(1<<i);
    return num & bitMask;
}

int main(){
    cout<<clearIthBit(6,1)<<endl;
    cout<<~(1<<1) ;//val is -3
    return 0;
}
