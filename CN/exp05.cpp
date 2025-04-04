#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Comparator function for sorting edges based on weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

struct Graph {
    int V, E;
    vector<Edge> edges;
};

Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    return graph;
}

struct subset {
    int parent, rank;
};

int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(Graph graph) {
    vector<Edge> result;
    int e = 0, i = 0;

    // Sort edges based on weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    subset* subsets = new subset[graph.V];
    for (int v = 0; v < graph.V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < graph.V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    cout << "Edges in MST:\n";
    for (size_t j = 0; j < result.size(); j++) {
        cout << result[j].src << " - " << result[j].dest << " : " << result[j].weight << endl;
    }

    delete[] subsets;
}

int main() {
    int V = 4, E = 5;
Graph graph = createGraph(V, E);

// Randomized edges and weights
graph.edges.push_back((Edge){0, 1, 12});
graph.edges.push_back((Edge){0, 2, 8});
graph.edges.push_back((Edge){0, 3, 7});
graph.edges.push_back((Edge){1, 2, 14});
graph.edges.push_back((Edge){2, 3, 3});


    KruskalMST(graph);

    return 0;
}
