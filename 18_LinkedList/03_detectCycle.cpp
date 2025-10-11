#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        //  No need to update tail here
    }

   
    bool isCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                cout << "Cycle exists\n";
                return true;
            }
        }
        cout << "Cycle doesn't exist\n";
        return false;
    }

    void removeCycle() {
        Node* slow = head;
        Node* fast = head;

        // Step 1: detect
        bool cycleFound = false;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                cycleFound = true;
                break;
            }
        }

        if (!cycleFound) {
            cout << "No cycle to remove\n";
            return;
        }

        // Step 2: move slow to head
        slow = head;
        if(slow==fast){//special  cast : tail->head
            while(fast->next != slow){
                fast=fast->next;
            }
            fast->next=NULL;//remove ccle
        }else{
            Node* prev = fast;
            while(slow!=fast){
                slow=slow->next;
                prev = fast;
                fast=fast->next;
            }
            prev->next = NULL;
        }
    }

    void print() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < 50) {
            cout << temp->data << "->";
            temp = temp->next;
            count++;
        }
        cout << "NULL\n";
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    ll.print();  // 5->4->3->2->1->NULL

          
    ll.tail->next = ll.head; // create cycle
     ll.print();

    ll.isCycle();     // Cycle exists
    ll.removeCycle(); // Cycle removed
    ll.isCycle();     // Cycle doesn't exist
    ll.print();       // 5->4->3->2->1->NULL

    return 0;
}
