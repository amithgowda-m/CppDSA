//A friend class or a friend function can access private and protected members of the other classes in which it is decclared as a friend

#include <iostream>
#include <string>
using namespace std;

class A{
    // public:
    string secret = "secret data";
    friend class B;
    friend void revealSecret(A &obj);
    
};

class B{ // becomes a friend of A class
public:
    void showSecret(A &obj){
        cout<<obj.secret<<endl;
    }
};

void revealSecret(A &obj){
    cout<<obj.secret<<endl;
}

int main(){
    A a1;
    B b1;
    b1.showSecret(a1);
    revealSecret(a1);
    return 0;
}

