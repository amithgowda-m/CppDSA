#include <iostream>
#include <vector>
#include <string>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;
public:
    Graph(int v,bool isUndir){
        this->V=v;
        l=new list<int>[v];
        this->isUndir=isUndir;
    }
    
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void pathHelper(int src,int dest,string &path,vector<bool> &vis){
        if(src==dest){
            cout<<path<<dest;
            cout<<endl;
            return;
        }
        vis[src]=true;
        path+=to_string(src);
        for(auto v: l[src]){
            if(!vis[v]){
                pathHelper(v,dest,path,vis);
            }
        }
        path=path.substr(0,path.size()-1);
        vis[src]=false;
    }

    void printAllPath(int src,int dest){
        vector<bool> vis(V,false);
        string path="";
        pathHelper(src,dest,path,vis);
    }

    void print(){
        for(int i=0;i<V;i++ ){
            cout<<i<<" : ";
            for(auto v: l[i]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph graph(6,false);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.addEdge(2,3);
    graph.addEdge(0,3);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(3,1);
    graph.print();
    graph.printAllPath(5,1);
    return 0;


}