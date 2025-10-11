#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node *head;
    Node *tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){// push a val to front of existing ll or creates one ll
        Node *newNode = new Node(val); // dynamic

        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head; // newly created node's next will point old head i,e it points to next element if pushed front
            head = newNode;       // now head points newnode
        }
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void iterativeSearch(int val){
        Node *temp = head;
        int count = 0;

        if (head == NULL){
            cout << "Empty list";
            return;
        }

        while (temp != NULL){
            if (temp->data == val){
                cout << val << " is at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << val << " not found in list" << endl;
    }
    int helper(Node* temp,int key){
         if (temp==NULL){
              return -1;//If you’ve reached NULL, that means you’ve gone past the end of the linked list and didn’t find the key. So you return -1 (a signal that the key doesn’t exist).
         }
         
        if (temp->data == key){
            return 0;//If the current node’s data matches the key
//Return 0 because the current node is 0 steps away from itself (i.e., index 0 relative to this point in recursion).
        }

        int idx = helper(temp->next,key);//This line is the “recursive call” — it says, “I didn’t find it here, so let’s check the next node.”
// This keeps happening until either:
// You find the key (and return 0), or
// You reach the end (temp == NULL, and return -1).
        if (idx==-1){
            return -1;
        }
        return idx+1;
    }

    //searchRecursive is the public function you call from outside.
// helper is a private recursive function that actually does the searching.
    int searchRecursive(int key){
        return helper(head,key);
    }

    void reverse(){
        Node* prev = NULL;
        Node* cur = head;
        Node* next = NULL;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

//     void reverse() {
//     if (head == NULL || head->next == NULL) return; // empty or single-node list

//     Node* prev = NULL;
//     Node* cur = head;
//     Node* next = NULL;

//     Node* oldHead = head; // store old head; will become new tail

//     while (cur != NULL) {
//         next = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = next;
//     }

//     head = prev;
//     tail = oldHead; // update tail
// }

    void removeNth(int n) {
    if (head == NULL) return; // empty list

    // Step 1: calculate size
    Node* temp = head;
    int size = 0;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // If n is invalid
    if (n > size || n <= 0) return;

    // If we need to delete the head
    if (n == size) {
        Node* toDel = head;
        head = head->next;
        cout << "Deleting: " << toDel->data << endl;
        delete toDel;
        return;
    }

    // Step 2: find node before target
    Node* prev = head;
    for (int i = 1; i < size - n; i++) {
        prev = prev->next;
    }

    // Step 3: delete target node
    Node* toDel = prev->next;
    cout << "Deleting: " << toDel->data << endl;

    prev->next = toDel->next;
    delete toDel;
}

void removeNth2pointer(int n) {
    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) return; // n > length
        fast = fast->next;
    }

    // If fast is NULL, we remove the head
    if (fast == NULL) {
        Node* toDel = head;
        head = head->next;
        cout << "Deleting: " << toDel->data << endl;
        delete toDel;
        return;
    }

    // Move both pointers until fast reaches the end
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* toDel = slow->next;
    cout << "Deleting: " << toDel->data << endl;
    slow->next = slow->next->next;
    delete toDel;
}


};

int main(){//iin ll pos stars forrm zero
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    
    ll.iterativeSearch(3);
    cout<<"\n Recursive Search Result "<<ll.searchRecursive(2)<<"\n";
    ll.reverse();
    ll.print();
    ll.removeNth(1);

    ll.print();
    return 0;
}