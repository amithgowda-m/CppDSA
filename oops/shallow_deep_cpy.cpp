#include <iostream>
using namespace std;

class Car{
    public: 
        string name;
        string color;
        int *mileage;

    Car(string name, string color){
        this->name = name;
        this->color = color;
        mileage = new int;//allocated dynnamically
        *mileage = 12;
    }
    Car(Car &original){//for deep copy we define our owm copy construcotr
        cout<<"\ncopy constructor running\n";
        name = original.name;
        color=  original.color;
        mileage=new int();

        *mileage=*original.mileage;  //here one more pointer is created which points to the same memory location but its value is not allocated
    }
    //destructor
    ~Car(){//when object comes out of the scope of a funcition default destructor gets ceated and it is called automatically
        //default destructor deallocate memory only for statically declared variable
        cout<<"\nobject deletion.. \n";
        if (mileage!=NULL)//to deallocate dynamically allloted memeory
        {
            delete mileage;
            mileage = NULL;
        }
    }
};
// to frre the dynamically allocated memory we should creater custorm destructor
//in shallow copy the memory wont have created twice
//in deep constructor memory allocated differently
int main(){
    Car c1("Range rover Velar","White");
    Car c2(c1);
    cout<<c2.color<<endl;
    cout<<c2.name<<endl;
    cout<<c2.mileage<<endl;// as we can see dynamically allocated data  is stored its referrence only
    cout<<*(c2.mileage)<<endl;
    cout<<c1.mileage<<endl;
    cout<<"To get its  value do dereference : "<<*(c2.mileage)<<endl;
    // if i change c2 mileage it will get reflected to c1
    *(c2.mileage)=10;
    cout<<"C1 milege after changing c2 is : "<<*c1.mileage;//this tells they both point to same memory location 
    return 0;//when this comes default automatic destroctor created and memeory get de alocated

}

//shallow copy copies references to original array but array remans same
//deep copy created a bready new copy of the array

///compiler generally creates a shallow copy for array
//we need to define copy constructor when deeep copy is needed i.e when classs containe pointer s to dynamically allocated memeory



















