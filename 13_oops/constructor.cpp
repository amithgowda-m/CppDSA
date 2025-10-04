#include <iostream>
using namespace std;

class Car{
    string name;
    string color;

public:
//here we have multicple constructor that is called as constructor overloading
//compile knows which constructor to be used when object is created
    Car(){//default constructor , if we dont explicitly declare a constructor it gets called
        cout<<"Calling non parameterized constructot";
    }
    // Car(string nameVal, string colorVal){//constructor 
    //     //it is not necessary to declare explicitly the constructor
    //     cout<<"Construcor is called, object is created";
    //     name = nameVal;
    //     color=colorVal;
    // }
    Car(string name, string color){//constructor 
        //it is not necessary to declare explicitly the constructor
        cout<<"Construcor is called, object is created";
        this->name = name;//this is one more type when variable name is same
        this->color=color;//this is a special type of object which points to currentt object 
        //this->prop is same as *(this).prop
    }
    void start(){
        cout<<"car has started...\n";
    }
    void stop(){
        cout<<"car has stopped";
    }

    //Getter
    string getName(){
        return name;
    }
};

int main(){
    Car c1("Range Rover Velar ","white");//when i created contructor itself called
    cout<<"\ncar Name : "<<c1.getName()<<"\n";
    Car c3("Land Cruizer","white");
    Car c2;
    return 0;
} 