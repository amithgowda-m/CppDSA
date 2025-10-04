#include <iostream>
using namespace std;

int clearIth(int num , int ith ){
    for (int i = 0; i < ith ; i++)
    {
        int bitMask = ~(1<<i);
        num = num & bitMask;
    }
    return num;
}

int mamApproach(int num,int i){ // this is efficient approach
        int bitMask = ~0;
        int bit = bitMask<<i;
        num = num&bit;
        return num;
}
int main (){
    cout<<clearIth(15,2);
    cout<<" this is my approach \n";
    cout<<mamApproach(15,2);
    return 0;
}