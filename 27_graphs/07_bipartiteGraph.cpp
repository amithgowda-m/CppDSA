#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // Helper function to handle a single component
    bool bfsHelper(int src, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0; // Start coloring with 0

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : l[curr]) {
                if (color[neighbor] == -1) { // Not visited
                    color[neighbor] = 1 - color[curr]; // Assign opposite color
                    q.push(neighbor);
                } else if (color[neighbor] == color[curr]) {
                    return false; // Conflict found
                }
            }
        }
        return true;
    }

    bool isBipartite() {
        vector<int> color(V, -1); // -1 means unvisited
        //Loop through all vertices to handle disconnected graphs
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfsHelper(i, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    ~Graph() {
        delete[] l;
    }
};

int main() {
    // Case 1: A simple Square (Bipartite)
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    cout << "Graph 1 is Bipartite: " << (g1.isBipartite() ? "Yes" : "No") << endl;

    // Case 2: A Triangle (Not Bipartite - Odd Cycle)
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    cout << "Graph 2 is Bipartite: " << (g2.isBipartite() ? "Yes" : "No") << endl;

    return 0;
}