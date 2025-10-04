#include <iostream>
using namespace std;

int* ret(){
    int *ptr = new int;
    *ptr = 1200;
    cout<<"ptr points to "<<*ptr;
    return ptr;
}
int main(){
    int *x = ret();
    cout<<"\n the valur is"<<*x;
    return 0;
}
