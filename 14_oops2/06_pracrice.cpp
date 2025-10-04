#include <iostream>
#include <string.h>
using namespace std;

class A{
public:
    A(){ cout << "Constructor A\n"; };
    ~A(){ cout<<"Destructor A\n"; };
};

class B : public A{
public:
    B(){ cout<<"Contructor B\n"; };
    ~B(){ cout <<"Destructor B\n"; };
};

int main(){
    //A a1;// first created object exits last
    B b1;// baby class first call ca then cb
    return 0;
}