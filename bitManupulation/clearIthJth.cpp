#include <iostream>
using namespace std;

int ithJth(int num,int i,int j){
    for (int t = i;  t<= j; t++){
        int bitMask = ~(1<<t);

        num = num & bitMask;
    } 
    return num;
}

int main(){
    cout<<ithJth(15,1,3);
    return 0;
}