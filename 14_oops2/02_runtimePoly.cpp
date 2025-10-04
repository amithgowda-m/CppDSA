//types of Runtime polymorphism are function overriding 
//function overriding :  Parent & Child both contain the same fnction with diferet implementation the parent class function is  saif to be overridden
//that means at run time it will be decides and child class function is to be executed
//one more type of runtime polymorphism is Virtual functions

//A virtual function is a member function that you expect to be redifined in derived classes
//virtual functions are dynamic in nature
//defined by the keyword "virtual " inside a base class and are always declared with a base class and overriddern in a child class
//A virtual fuction is called during runtime


#include <iostream>
using namespace std;

class Parent{
public:
    void show(){
        cout<<"This is Parent class show";
    }

    virtual void hello(){
        cout<<"Parent hello..\n";
    }
};

class Child : public Parent{
public:
    void show(){
        cout<<"child class show...\n";
    }
    void hello(){
        cout<<"child hello..\n";
    }
};

int main(){
    Child child1;
    Parent *ptr;// this pointer points to parent class object
    
    ptr = &child1;//Run time Binding
    ptr->hello();//virutal funciton

    child1.show(); 
    return 0;
}














