#include <iostream>
using namespace std;

int main(){
    int a = 10,*pa;
    pa =&a;
    cout<<pa<<"\n"<<*pa;
    *pa =20;//called dereference
    cout<<"\n"<<a;
    return 0;w
}