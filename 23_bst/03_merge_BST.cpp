#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int data){
            this->data = data;
            left=right=NULL;
        }
};

void getInorder(Node* root,vector<int>& nodes){
    if(root==NULL){
        return;
    }
    getInorder(root->left,nodes);
    nodes.push_back(root->data);
    getInorder(root->right,nodes);
}

Node* vecToBST(vector<int>nodes,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* root = new Node(nodes[mid]);
    root->left= vecToBST(nodes,st,mid-1);
    root->right=vecToBST(nodes,mid+1,end);
    return root;
}

Node* mergeBST(Node* root1,Node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1,nodes1);
    getInorder(root2,nodes2);

    int i=0,j=0;
    while(i<nodes1.size()&&j<nodes2.size()){
        if(nodes1[i]<=nodes2[j]){
            merged.push_back(nodes1[i++]);
        }
        else{
            merged.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }
    return vecToBST(merged,0,merged.size()-1);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root1=new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);


    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right= new Node(12);

    Node* final = mergeBST(root1,root2);
    cout<<"Inorder or root1 before merging : ";
    inorder(root1);
    cout<<"\nInorder or root2 before merging : ";
    inorder(root2);
    cout<<"\nInorder of merged tree : ";
    inorder(final);

}


