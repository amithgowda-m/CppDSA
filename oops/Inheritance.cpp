#include <iostream>
using namespace std;

class Animal{
    public:
        string color;
    private :
        string name;
     
    protected:
        void eat(){
            cout<<"eats\n";
        }
        int id;
    private:
        void breathe(){
            cout<<"breathe\n";
        }
};

class Fish: public Animal{//if i dint write access modifier , in cpp by default inheritance is private
    //example of single inheritance
    public:
        int fins;
        
        // string name = "gold";
        void swin(){
            //breathe();//as breathe is private i get error here
            eat();//as eat is protected i can access it here 
            cout<<"swim\n";
        }
};

int main(){
    Fish f1;
    f1.fins =2;
    cout<<f1.fins<<endl;
    f1.swin();
    //f1.eat();// i dfd eat protected in animal i get error here
  //f1.breathe();//as eat is private i get error here
    return 0;
}