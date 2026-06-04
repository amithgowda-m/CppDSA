#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l;
    bool isUndir;
public:
    Graph(int v,bool isUndir){
        this->V=v;
        l = new list<pair<int,int>>[v];
        this->isUndir =isUndir;
    }

    void addEdge(int v,int u,int wt){
        l[u].push_back(make_pair(wt,v));
        if(isUndir){
            l[v].push_back(make_pair(wt,u));
        }
    }
    void prims(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans=0;
        vector<bool> mst(V,false);

        pq.push(make_pair(0,src));
        while(pq.size()>0){
            int u = pq.top().second;
            int wtg = pq.top().first;

            pq.pop();
            if(!mst[u]){
                mst[u]=true;
                ans+=wtg;
                for(auto lst : l[u]){
                    int currWt = lst.first;
                    int v = lst.second;
                    pq.push(make_pair(currWt,v));//push wt , v
                }
            }
        }
        cout<<"Final Cost : "<<ans<<endl; 
    }
};

int main(){
    Graph graph(4,true);
    graph.addEdge(0,1,10);
    graph.addEdge(1,3,40);
    graph.addEdge(0,2,15);
    graph.addEdge(3,2,50);
    graph.addEdge(0,3,30);
    graph.prims(0);
    return 0;
}