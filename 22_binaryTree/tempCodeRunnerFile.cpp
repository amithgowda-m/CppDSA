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