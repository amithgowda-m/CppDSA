#include <iostream>
#include <vector>
using namespace std;

//Create Stack using vector 

template <class T>
class Stack{
    vector <T> vec;
public:
    void push(int val){//O(1)
        vec.push_back(val);
    }

    bool isEmpty(){
        return vec.size() ==0;
    }

    void pop(){//O(1)
        if(isEmpty()){
            cout<<"Stack is Empty";
            return;
        }
        vec.pop_back();
    }

    T top(){//O(1)
        if(isEmpty()){
            cout<<"Stack is Empty";
            return -1;
        }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }
};

int main(){
    Stack <char> s;//here we can replace int,string, or any

    s.push('c');//las in
    s.push('b');
    s.push('a');

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
