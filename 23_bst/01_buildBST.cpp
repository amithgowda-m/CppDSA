#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            left = right =NULL;
        }
};

Node* insert(Node* root,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

Node* buildBst(int arr[],int n){
    Node* root =NULL;
    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool searchBST(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    else if(root->data<key){
        return searchBST(root->right,key);
    }
    else{
        return searchBST(root->left,key);
    }
    
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* successor = root->right;
            while (successor->left)
                successor = successor->left;

            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

void printInRange(Node* root,int st,int en){
    if(root==NULL){
        return;
    }
    if(root->data <=en && root->data >=st){
        printInRange(root->left,st,en);
        cout<<root->data<<" ";
        printInRange(root->right,st,en);
    }
    else if(root->data<st){
        printInRange(root->right,st,en);
    }
    else{
        printInRange(root->left,st,en);
    }
}

void printPath(const vector<int> &path) {
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;
}

void root2Leaf(Node* root, vector<int> &path) {
    if (root == NULL) return;

    // Choose
    path.push_back(root->data);

    // If leaf node → print path
    if (root->left == NULL && root->right == NULL) {
        printPath(path);
    } else {
        // Explore
        root2Leaf(root->left, path);
        root2Leaf(root->right, path);
    }

    // Un-choose (Backtrack)
    path.pop_back();
}

Node* buildSortedToBST(int arr[], int st, int end) {
    if (st > end) return NULL;

    int mid = st + (end - st) / 2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildSortedToBST(arr, st, mid - 1);
    curr->right = buildSortedToBST(arr, mid + 1, end);

    return curr;
}


int main(){
    int arr[6]={5,1,3,4,2,7};
    Node* root = buildBst(arr,6);
    cout<<"Printing inorder : ";
    inorder(root);
    int val =4;
    cout<<endl;
    cout<<"Searching(true:1/false:0) : "<<searchBST(root,val);
    cout<<endl;
    cout<<"Printing : ";
    printInRange(root,3,7);
    
    deleteNode(root,3);
    cout<<endl;
    cout<<"After deleting 3 : ";
    inorder(root);
    cout<<endl;
    vector<int>path;
    cout<<"Root to leaf Path : ";
    root2Leaf(root,path);
    cout<<endl;
    int nodes[7]={3,4,5,6,7,8,9};
    Node* build = buildSortedToBST(nodes,0,6);
    inorder(build);
    return 0;
}