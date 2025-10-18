#include <iostream>
#include <deque>
using namespace std;


class Stack{
    deque<int> dq;
public:
    void push(int data){
        return dq.push_front(data);
    }
    void pop(){
        return dq.pop_front();
    }
    int top(){
        return dq.front();
    }
    bool empty(){
        return dq.empty();
    }
};

int main(){
    Stack s;
    for(int i=0;i<=5;i++){
        s.push(i);
    }

    for(int i=0;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
