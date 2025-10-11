#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;


//to get top== ll head
//to pop ==pop__back o linked list head move to next element

//create stack using linked list
template<class T>
class Node{
public:
    T data; 
    Node<T>* next;

public:
  Node(T val){
    data =  val;
    next = NULL;
  }  
};

template<class T>
class Stack{//push=push front in ll
    Node<T>* head; 
    
    //list<T> ll;//wed dont want how it is implemented so we make it private


public:
    Stack(){
        head = NULL;
    }
    void push(T val){
        // ll.push_front(val);
        Node<T>* newNode = new Node<T>(val);
        if(head==NULL){
            head = newNode;
        }else{
            newNode->next= head;
            head = newNode;
        }
    }

    void pop(){
        //ll.pop_front();
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node<T>* temp =  head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top(){
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return T();
        }
        return head->data;
    }

    bool isEmpty(){
        ///return ll.size()==00;
        return head==NULL;
    }
};

int main(){
    Stack <int> s;
    s.push(3);
    s.push(2);
    s.push(1);//last in ie recently in
   // s.pop();//remove 1 fist
    cout<<s.top();
    while(!s.isEmpty()){
        cout<<s.top()<<" ";//see the top value
        s.pop();//remove from the top
    }
    // s.pop();
    // cout<<s.top();

    cout<<endl;
    return 0;
}