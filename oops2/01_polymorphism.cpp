//polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used
//like constructor overloading

//two types of polymorphism are Compile time polymorphism and run time polymorphism
//complile time polymorphism : function overloading  and operator overloading

//function overloading :  name of functions or cinstructor same but parameters differnt 
//operator overloading : using operator in diiferent ways but name same

#include <iostream>
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

int main(){
    Print obj1;
    obj1.show(3);
    obj1.show("Amith");
    return 0;
}