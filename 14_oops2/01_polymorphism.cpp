//polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used
//like constructor overloading

//two types of polymorphism are Compile time polymorphism and run time polymorphism
//complile time polymorphism : function overloading  and operator overloading

//function overloading :  name of functions or cinstructor same but parameters differnt 
//operator overloading : using operator in diiferent ways but name same

#include <iostream>
#include <string>
using namespace std;

class Print{
public:
  void show(int x){
    cout<<"int : "<<x<<endl;
  }  
  void show(string str){
    cout<<"string : "<<str<<endl;
  }
};

class Complex{
    int real;
    int img;
public:
    Complex(int r,int i){
        real = r;
        img = i;
    }

    void showNum(){
        cout<<real<<" + "<<img<<"i\n";
    }
    Complex operator + (Complex &c2){
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal,resImg);
        cout << "res  : ";
        c3.showNum();
        return c3;
    }
};

int main(){
    Complex c1(3,4);
    Complex c2(3,2);
    c1.showNum();
    Print obj1;
    obj1.show(3);
    c1+c2;
    obj1.show("Amith");

    Complex c3 = c1+c2;
    c3.showNum();
    return 0;
}