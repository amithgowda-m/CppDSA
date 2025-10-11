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
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert_middle(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 1) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 2; i++) {
            if (temp == NULL) {
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) tail = newNode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void pop_back() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    Node* splitAtMid(Node* head) {
        if (!head || !head->next) return NULL;
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) prev->next = NULL; // split
        return slow; // right head
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* rightHead = splitAtMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        return merge(left, right);
    }
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next = prev;

            prev=curr;
            curr=next;
        }

        return prev;
    }

    void zigZagLL(Node* head){
        Node* rightHead = splitHead(head);
        Node* rightHeadRev = reverse(rightHead);

        //alternate merging: 1st head=head second ll head = right head
    }
};

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printLL(); // 1->2->3->NULL

    ll.push_back(4);
    ll.push_back(5);
    ll.insert_middle(100, 3); // insert 100 at position 3
    ll.printLL(); // 1->2->100->3->4->5->NULL

    ll.pop_front();
    ll.printLL(); // 2->100->3->4->5->NULL

    ll.pop_back();
    ll.printLL(); // 2->100->3->4->NULL

    ll.head = ll.mergeSort(ll.head);
    ll.printLL(); // Sorted list: 2->3->4->100->NULL

    return 0;
}
