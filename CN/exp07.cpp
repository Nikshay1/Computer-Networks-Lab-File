#include <iostream>
#include <climits>
#define V 4
using namespace std;

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Router " << src << " shortest paths:\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " distance: " << dist[i] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, 7, 0},
        {3, 0, 1, 8},
        {7, 1, 0, 4},
        {0, 8, 4, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
