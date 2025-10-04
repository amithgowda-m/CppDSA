#include <iostream>
using namespace std;

int updateIth0(int num,int i, int val){
    int bitMask = ~(1<<i);//to replace i th bit by zero
    return num & bitMask;
}

int updateIth1(int num ,int i,int val){
    int bitMask = 1<<i;
    return num | bitMask;
}

int newUpdate(int num, int i ,int val){
    int bitClear = ~(1<<i);
    int bitMask = 1<<i;
    num = num & bitClear;
    if (val ==0)
    {
        return num;
    }
    else{
        return num | bitMask;
    }
}

int excUpdate(int num,int i, int val){// this approach is excellent
    num = num & ~(1<<i); //clear ith bit
    
    num =  num | (val<<i); // update ith bit
    return num;
}
int main(){
    cout<<updateIth0(7,3,1);
    cout<<"\n";
    cout<<updateIth1(7,3,1);
    cout<<"\n";
    cout<<newUpdate(7,3,1);
    cout<<"\n";
    cout<<excUpdate(7,3,1);


    return 0; 
}
  