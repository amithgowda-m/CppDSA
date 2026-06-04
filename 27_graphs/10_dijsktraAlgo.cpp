// This algorithm is used for finding the shortest path from src to all vertices for a weighted graph Fails if the graph contains negative edge weights.(Fails if the graph contains negative edge weights.)
#include <iostream>
#include <queue> 
#include <stack>
#include <vector>
#include <list>
#include <climits> // Added for INT_MAX

using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    } 
};

void dijkstra(int src, vector<vector<Edge>> graph, int V) {
    // Min-heap storing pairs of (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);
    
    //  Push the actual 'src' variable 
    pq.push(make_pair(0, src)); 
    dist[src] = 0;
    
    while(pq.size() > 0) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        // Optimization: If we found a shorter path to 'u' already, skip processing its neighbors again
        if (current_dist > dist[u]) continue;
        
        for(auto e : graph[u]) {
            if(dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }
    
    // Print the final distances
    for(int d : dist) {
        if (d == INT_MAX)
            cout << "INF ";
        else
            cout << d << " ";
    }
    cout << endl;       
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));
    
    dijkstra(0, graph, V);
    
    return 0;
}