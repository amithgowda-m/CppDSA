//Abstraction  : hiding all unnecessary details and showing only the important parts
//Abstract: classes with pure virtual functions
//abstract classes are used to privide a basee class form whcih other classes can be derived
//they cannot be instantiated and are mean to be inherited
//Abstract classes are typically used to define an interface for derived classes
//abstract classes have atleast one pure virtual functions

//pure virtual function(abstract function) : with no definition/logic it is declared by assigning 0  at the time of declaration

#include <iostream>
using  namespace std;

class Shape{//abstract class as it has pure virtual funciton
public:
    virtual void draw()=0;//abstract fnx, pure virtual fincruo
};

class Circle : public Shape{// here base class provide definition that the shape is circle
public:
    void draw(){
        cout<<"draw a circle\n";
    }
};
class Square : public Shape{
public:
    void draw(){
        cout<<"draw a square\n";
    }
};

int main(){
    Circle cir1;
    cir1.draw();
    Square sq1;
    sq1.draw();
    return 0;
}

//if i instantiate abstract class shape ill get error 
