#include <iostream>
using namespace std;

void func(){
    int size;
    cin >> size;

    int *ptr = new int[size]; 
    int x=1;
    for (int i = 0; i < size; i++)
    {
        ptr[i]=x;
        cout<<*(ptr+i)<<" ";
        x++;

    }
    delete[]ptr;
    
}

int main(){
    func();
    return 0;
}