#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define V 5  // Number of vertices

int minDistance(int dist[], bool visited[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++){
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " Distance from Source: " << dist[i] << endl;
}

int main(){
    int graph[V][V] = {
        {0, 15, 0, 25, 80},
        {15, 0, 40, 0, 0},
        {0, 40, 0, 15, 5},
        {25, 0, 15, 0, 45},
        {80, 0, 5, 45, 0}};
    dijkstra(graph, 0);
    return 0;
}
