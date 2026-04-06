#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph{
    int v;
    list<int> * l;

public: 
    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0;u<v;u++){
            cout<<u<<" : ";
            for(auto v : l[u]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(v,false);
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(auto v : l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }

    void dfs(int u,vector<bool>&visited){
        visited[u]=true;
        cout<<u<<" ";
        for(auto p: l[u]){
            if(!visited[p]){
                dfs(p,visited);
            }
        }
    }
    void dfsHelper(){
        vector<bool> visited(v,false);
        dfs(0,visited);
    }

    bool hasPath(int src,int dest,vector<bool> &visited){
        if(src==dest){
            return true;
        }
        visited[src]=true;
        for(auto v : l[src]){
            if(!visited[v]){
                hasPath(v,dest,visited);
            }
        }
        return false;
    }
    void hasPathHelp(int src,int dest){
        vector<bool>visited(v,false);
        int ans = hasPath(src,dest,visited);
        if(ans){
            cout<<"False";

        }
        else{
            cout<<"True";
        }
    }
};

int main(){
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(4,5);
    graph.addEdge(3,5);
    graph.addEdge(5,6);

    graph.print();
    graph.bfs();
    cout<<endl;
    graph.dfsHelper();
    cout<<endl;
    
    graph.hasPathHelp(1,3);
    return 0;

}