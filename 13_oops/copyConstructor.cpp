#include <iostream>
using namespace std;

class Car{
    public:
        string name;
        string color;
    Car(string name,string color){
        this->name = name;
        this->color = color;
    }
    //custom copy constructor

    Car(Car &original){//if we dont decelare it explicity there will  be a default copy constructor which gets called
        cout<<"\nRunning custom copy constructor\n";
        name = original.name;
        color = original.color;
    }
};

int main(){
    Car c1("Range rover Velar","white");
    Car c2(c1);//sending whole object as an arguement
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}