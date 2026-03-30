#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>* l;//\ make this pair then it beocme weighted graph

public:
    Graph(int V){
        this->V =V;
        l = new list<int> [V];
        // int* arr;
        // arr= new int [V]; this is same as above
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
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
};

int main(){
    Graph graph(5);
    //undirected un weighted graph
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.print();
    //to convert this to weighted graph make list<pair<int,int>>[V] sotre neighbour,weight
    return 0;
}