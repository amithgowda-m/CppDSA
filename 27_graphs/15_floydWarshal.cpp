#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Graph {
    int V;
    vector<vector<int>> dist;
    bool isUndir;

public:
    // Constructor
    Graph(int v, bool isUndir) {
        this->V = v;
        this->isUndir = isUndir;
        
        // Initialize the distance matrix with INF
        dist.resize(V, vector<int>(V, INT_MAX));

        // The distance from a vertex to itself is always 0
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
        }
    }

    // Add an edge to the adjacency matrix
    void addEdge(int u, int v, int wt) {
        dist[u][v] = wt;
        if (isUndir) {
            dist[v][u] = wt;
        }
    }

    // Floyd-Warshall Algorithm
    void floydWarshall() {
        // k acts as the intermediate vertex
        for (int k = 0; k < V; ++k) {
            // i acts as the source vertex
            for (int i = 0; i < V; ++i) {
                // j acts as the destination vertex
                for (int j = 0; j < V; ++j) {
                    
                    // If vertex k is on a shorter path from i to j, update dist[i][j]
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    
                }
            }
        }
        
        printMatrix();
    }

    // Utility function to print the resulting matrix
    void printMatrix() {
        cout << "Shortest Distance Matrix:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INT_MAX)
                    cout << "INF\t";
                else
                    cout << dist[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(4, false); // Directed graph
    
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 3, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);

    graph.floydWarshall();

    return 0;
}