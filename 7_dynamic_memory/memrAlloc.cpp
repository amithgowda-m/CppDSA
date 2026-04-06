#include <iostream>
using namespace std;

int main(){
    int size;
    cin>>size;

    // new int[size];//allocated sze// its waste
    // arr[0]==*(arr+0)
    int *ptr = new int[size];
    int x =1;

    for (int i = 0; i < size; i++){
       ptr[i]=x;
       cout<<ptr[i]<<" ";
       x++;
    }
    delete[] ptr;//frees memory
}