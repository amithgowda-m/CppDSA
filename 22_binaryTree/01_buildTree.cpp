#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//base case build root node then do recursion

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            left=right=NULL;
        }
};

static int idx = -1;//when we increment it will continue its value in bw function call
// //Static means:
// – It keeps its value between function calls,
// – And only gets initialized once.

Node* buildTree(vector<int> &nodes){//vector<int> nodes  = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);//1
    //build left&right subtree
    currNode->left = buildTree(nodes);//2
    currNode->right = buildTree(nodes);//3
    return currNode;
}

void preorder(Node* root){//O(n)
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "; 
}

void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* curr = Q.front();
        Q.pop();
        if(curr==NULL){
            cout<<endl;
            if(Q.empty()){
                break;
            }
            Q.push(NULL);
        }else{
              cout<<curr->data;
        
              if(curr->left!=NULL){
               Q.push(curr->left);
               }
               if(curr->right!=NULL){
               Q.push(curr->right);
        }
        cout<<" "; 
        }
    }
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftht = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftht,rightHt)+1;
    return currHt;
}

int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftC = count(root->left);
    int rightC = count(root->right);
    return leftC+rightC+1;
}

int sum(Node* root){
    if(root ==NULL){
        return 0;
    }
    int leftS = sum(root->left);
    int rightS = sum(root->right);
    int sum = leftS+rightS+root->data;
    cout<<"\nSum = "<<sum;
    return sum;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);
    int throughRoot = height(root->left) + height(root->right) + 1;
    return max(throughRoot, max(leftD, rightD));
}

pair<int,int> diameterx(Node* root){//O(n)
    if(root==NULL){
        return make_pair(0,0);
    }
    //diameter,height
    pair<int,int> leftInfo = diameterx(root->left);
    pair<int,int> rightInfo = diameterx(root->right);

    int currDiam = leftInfo.second+rightInfo.second+1;
    int finalDiam= max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiam,finalHt);    
}
 
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;

    if (root1->data != root2->data) return false;

    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL) return true;     // empty tree is always subtree
    if (root == NULL) return false;       // main tree ended too early

    if (root->data == subRoot->data) {
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

void topView(Node* root){
    if(root==NULL){
        cout<<"No node exists";
        return ;
    }
    queue<pair<Node*,int>> Q;
    map<int,int> m;// key: horizontal distance and value: data

    Q.push(make_pair(root,0));
    while(!Q.empty()){
        pair<Node*,int>cur = Q.front();
        Q.pop();
        Node* currNode = cur.first;
        int curHd = cur.second;

        if(m.count(curHd)==0){///unique key curHd aagidre 
            m[curHd]= currNode->data;
        }
        if(currNode->left!=NULL){
            pair<Node*,int> left = make_pair(currNode->left,curHd-1);
            Q.push(left);
        }
        if(currNode->right!=NULL){
            pair<Node*,int> right = make_pair(currNode->right,curHd+1);
            Q.push(right);
        }

    }
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

bool rootToNodePath(Node* root,int n,vector<int> &path){//all the stl containers passed by value to reflect changes be funcitons
    //this functions travel all the nodes so O(n)
    if(root ==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isLeft = rootToNodePath(root->left,n,path);
    int isRight = rootToNodePath(root->right,n,path);

    if(isLeft||isRight){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root,int n1,int n2){//O(n)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root,n1,path1);
    rootToNodePath(root,n2,path2);

    int lca=-1;
    for(int i = 0,j=0;i<path1.size(),j<path2.size();i++,j++){
        if(path1[i]!=path2[i]){//first uncomman value
                return lca;
        }
        lca=path1[i];

    }
    return lca;


}

//Second approach for LCA

Node* LCA2(Node* root,int n1,int n2){
    if(root ==NULL){
        return root;
    }
    if(root->data == n1 ||root->data ==n2){
        return root;
    }
    Node* left = LCA2(root->left,n1,n2);
    Node* right = LCA2(root->right,n1,n2);

    if(left!= NULL && right!=NULL){
        return root;
    }
    
    return (left !=NULL)? left : right;
    
}

int dist(Node* root, int n) {
    if (root == NULL) return -1;

    if (root->data == n) return 0;

    int leftDist = dist(root->left, n);
    if (leftDist != -1) return leftDist + 1;

    int rightDist = dist(root->right, n);
    if (rightDist != -1) return rightDist + 1;

    return -1;
}


int minDist(Node* root,int n1,int n2){
    Node *lca =LCA2(root,n1,n2);
    int dist1 = dist(lca,n1);
    int dist2 = dist(lca,n2);

    return dist1+dist2;
}

int KthAncestor(Node * root,int node,int k){
    if(root==NULL){
        return - 1;
    }
    if(root->data ==node){
        return 0;
    }
    int leftDist = KthAncestor(root->left,node,k);
    int rightDist = KthAncestor(root->right,node,k);

    if(leftDist==-1 && rightDist ==-1){
        return -1;
    }

    int validVal = leftDist==-1 ? rightDist:leftDist;
    if(validVal+1 == k){
        cout<<k<<"th Ancestor of "<<node<<" : "<<root->data;
    }
    
    return validVal+1 ;
}

int transform(Node* root){
    if(root==NULL){
        
        return 0;
    }
    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld+rightOld;
    if(root->left!=NULL){
        root->data+= root->left->data;
    }
    if(root->right!=NULL){
        root->data+= root->right->data;
    }
    return currOld;


}
int main(){
    vector<int> nodes  = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
 //   subRoot->right = new Node(5);
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder Traversal : \n";
    levelOrder(root);
    
    cout<<"Height : "<<height(root);
    cout<<"\nCount of Nodes  :"<<count(root);
    cout<<"\nSum of Nodes : "<<sum(root);
    cout<<"\nDiameter of tree: "<<diameter(root);
    cout<<"\nDiameter of tree: "<<diameterx(root).first;

    cout<<"\nIs Subtree : "<<isSubtree(root,subRoot);

    cout<<"\nTop view : ";
    topView(root);
    cout<<"\nLowest Common ancestor : ";
    
    int n1=4,n2=5;
    int ans  = LCA(root,n1,n2);
    cout<<ans;
    
    cout<<"\nLowest Common ancestor 2nd approach : ";
    Node * ans2 = LCA2(root,n1,n2);
    cout<<ans2->data<<endl;

    int min = minDist(root,n1,n2);
    cout<<"Minimum distance bw nodes : "<<min<<endl;
    int k =1;
    KthAncestor(root,n2,k);
    cout<<endl;
    cout<< transform(root)<<endl;//will print node

    levelOrder(root);


    return 0;
}
// Why Node*?

// Node* means a pointer to a Node object.

// In C++, when you create objects dynamically ( during runtime), you don’t get the object directly you get a pointer to where it lives in memory.

// A pointer is just an address.
// That address lets you:

// • link this node to a parent
// • attach children to it
// • pass the node around without copying
// • build dynamic structures (trees, linked lists, graphs)

// A tree is fundamentally a linked data structure, so you must use pointers to connect nodes.

// Your Node has:

// Node* left;
// Node* right;

// Those store pointers.
// So currNode also must be a pointer—otherwise you couldn’t link these nodes together.

// Why new?

// new creates memory on the heap, not the stack.

// Heap memory is perfect for:

// • recursive structures
// • variable-sized structures
// • objects whose lifetime extends beyond the function call

// Your tree-building function keeps returning nodes up the recursion chain.
// So the objects must survive the end of the function.

// If you wrote:

// Node currNode(nodes[idx]);


// This creates the node on the stack, and dies as soon as the function ends.
// The parent would be pointing to a dead object—disaster.

// Using new:
// Node* currNode = new Node(nodes[idx]);
// creates the node on the heap, which:

// • stays alive
// • can be returned
// • can be assigned into left/right child pointers
// • forms a lasting tree until you delete it