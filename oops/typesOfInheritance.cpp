#include <iostream>
using namespace std;

class Animal{// multilevel
    public:
        void eat(){
            cout<<"Animal Eating..\n";
        }
        void breathe(){
            cout<<"\nAnimal Breathing\n";
        }
};

class Mammals : public Animal{
    // eat();
    // breathe();// we cant call parent class function inside other class
    public:
    string bloodType = "Warm";
};

class Dog:public Mammals{
    public: 
    string sound = "barks";
};

int main(){
    // Animal A ;//when we want to call derived class members from a object, object  it should be of derived clas only
    Dog A;
    cout<<A.bloodType<<"\n";
    A.eat();
    A.breathe();
    cout<<A.sound<<"\n";
    return 0;
}