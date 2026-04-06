#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int v){
        this->V = v;
        l = new list<int>[v];
    }

    void addEdge(int v,int u){
        l[u].push_back(v);
        l[v].push_back(u);
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
    
    bool undiCycleHelper(int src, int par,vector<bool> vis){//O(V+E)
        vis[src]=true;
        for(auto v: l[src]){
            if(!vis[v]){
                if(undiCycleHelper(v,src,vis)){//important line
                    return true;
                }
            }else{
                if(v!=par){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool>vis(V,false);
        return undiCycleHelper(0,-1,vis);
    }

};

int main(){
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,0);//makes cycle (edge which making is called back edge)
    graph.addEdge(0,3);
    graph.addEdge(3,4);

    graph.print();
    cout<<graph.isCycleUndir();
    return 0;
}

