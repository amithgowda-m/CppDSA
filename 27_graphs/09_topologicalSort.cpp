#include<iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;

public:

    Graph(int v, bool isUndir){
        this->V=v;
        l = new list<int>[v];
        this->isUndir=isUndir;
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int u=0;u<V;u++){
            cout<<u<<" : ";
            for(auto v: l[u]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void topologicalHelp(int src,vector<bool> &vis,stack<int> &s){
        vis[src]=true;
        for(auto v: l[src]){
            if(!vis[v]){
                topologicalHelp(v,vis,s);
            }
        }
        s.push(src);
    }

    void topoSort(){
        vector<bool> vis(V,false);
        stack<int> s;
        for(int u=0;u<V;u++){
            if(!vis[u]){
                topologicalHelp(u,vis,s);
            }
        }

        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

int main(){
    Graph graph(6,false);

    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,1);
    graph.addEdge(4,0);

    graph.print();
    
    graph.topoSort();
    return 0;
}