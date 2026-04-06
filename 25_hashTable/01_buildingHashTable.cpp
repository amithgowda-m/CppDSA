#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int val;
    string key;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }
    
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunc(string key) {
        int idx = 0;
        int p = 1; 
        for (int i = 0; i < key.size(); i++) {
            
            idx = (idx + (key[i] * key[i])) % totSize;
        }
        return idx % totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;
        
        totSize = 2 * totSize;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        currSize = 0; 
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                Node* prev = temp;
                temp = temp->next;
                delete prev; 
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashFunc(key);
        
        // Check if key already exists to update it instead of adding duplicate
        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                temp->val = val;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize / (double)totSize;
        if (lambda > 0.7) {
            rehash();
        }
    }

    bool exists(string key) {
        int idx = hashFunc(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) return true;
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFunc(key);  
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) { 
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    ~HashTable() {
        for (int i = 0; i < totSize; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] table;
    }

    void print(){
        for(int i = 0;i<totSize;i++){
            cout<<"idx"<<i<<"->";
            Node* temp= table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->val<<")->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void remove(string key){
        int idx = hashFunc(key);
        Node* temp = table[idx];
        Node* prev = temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }

};

int main() {
    HashTable ht;
    ht.insert("India", 150);
    ht.insert("Nepal", 10);
    ht.insert("Japan", 50);
    ht.insert("Canada", 350);
    ht.insert("US", 15);
    ht.insert("France", 57);
    ht.insert("Thailand", 120);

    if (ht.exists("India")) {
        cout << "India population : " << ht.search("India") << endl;
    }
    
    if (ht.exists("France")) {
        cout << "France population : " << ht.search("France") << endl;
    }
    ht.print();

    ht.remove("Canada");
    cout<<endl;

    ht.print();

    return 0;
}