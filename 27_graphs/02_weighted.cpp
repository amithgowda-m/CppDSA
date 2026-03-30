#include <iostream>
#include <vector>
#include <list>
using namespace std;
//building graph using adjacency list
class Graph {
    int V;
    list<pair<int,int>> *l; // adjacency list: (neighbor, weight)

public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back(make_pair(v, w)); // neighbor v with weight w
        l[v].push_back(make_pair(u, w)); // undirected graph
    }

    void print() {
        for(int u = 0; u < V; u++) {
            cout << u << " -> ";
            for(auto p : l[u]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }

  
};

int main() {
    Graph graph(5);
    // undirected weighted graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 8);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 12);

    graph.print();
 
    return 0;
}
