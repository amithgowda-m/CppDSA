#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class Info {
public:
    bool isBST;
    int minVal;
    int maxVal;
    int size;

    Info(bool isBST, int minVal, int maxVal, int size) {
        this->isBST = isBST;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->size = size;
    }
};

int maxSize = 0;

Info* largestBST(Node* root) {

    // Base case: empty tree is a BST of size 0
    // if (root == NULL) {
    //     return new Info(true, INT_MAX, INT_MIN, 0);
    // }

    // Leaf node is a BST of size 1
    if (root->left == NULL && root->right == NULL) {
        maxSize = max(maxSize, 1);
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    int currMin = min(root->data, min(leftInfo->minVal, rightInfo->minVal));
    int currMax = max(root->data, max(leftInfo->maxVal, rightInfo->maxVal));
    int currSize = leftInfo->size + rightInfo->size + 1;

    // Check BST condition
    if (leftInfo->isBST &&
        rightInfo->isBST &&
        root->data > leftInfo->maxVal &&
        root->data < rightInfo->minVal) {

        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}

void getInorder(Node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}

Node* BSTfromSorVec(vector<int>nodes,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* curr = new Node(nodes[mid]);
    curr->left = BSTfromSorVec(nodes,st,mid-1);
    curr->right = BSTfromSorVec(nodes,mid+1,end);
    return curr;
}
Node* balanceBST(Node* root){
    vector<int> nodes;
    getInorder(root,nodes);
    return BSTfromSorVec(nodes,0,nodes.size()-1);
}

void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    cout<<"Preoder before balancing : ";
    preorder(root);
    root= balanceBST(root);
    cout<<"\nPreoder after balancing : ";
    preorder(root);
    largestBST(root);
    cout<<"\nMax size : "<<maxSize<<endl;
    return 0;
}