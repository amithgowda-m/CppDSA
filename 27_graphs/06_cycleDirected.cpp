#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>* l;//\ make this pair then it beocme weighted graph
    bool isUndir;

public:
    Graph(int V,bool isUndir=true){
        this->V =V;
        l = new list<int> [V];
        // int* arr;
        // arr= new int [V]; this is same as above
        this->isUndir=isUndir;
    }

    void addEdge(int u,int v){//u-->v
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);//u--v
        }
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbors = l[u];
            cout<<u<<" : ";
            for(int v :neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    bool cycleDirHelper(int src,vector<bool> &vis,vector<bool> &recPath){
        vis[src]=true;
        recPath[src]=true;
        for(auto v: l[src]){
            if(!vis[v]){
                if(cycleDirHelper(v,vis,recPath)){
                    return true;
                }      
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    
    bool isCycleDir(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleDirHelper(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph graph(4,false);
    //undirected un weighted graph
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    graph.print();
    cout<<endl;
    cout<<graph.isCycleDir();
    return 0;
}