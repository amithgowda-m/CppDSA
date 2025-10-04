#include <iostream>
using namespace std;

class Base{
public:
    virtual void print(){
        cout<<"Base"<<endl;
    }
};

class Derived : public Base{
public:
    void print() override{//functioon override
        cout<<"Derived"<<endl;
    }
};

int main(){
    Base* b = new Derived();//pointer points to baby class object b will be object created dynamically
    //runtime polymorphism
    b-> print();
    delete b;
    return 0 ;
}