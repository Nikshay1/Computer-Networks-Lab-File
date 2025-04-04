#include <iostream>
using namespace std;

#define INF 99999
#define NODES 4

void distanceVector(int costMatrix[NODES][NODES]) {
    int dist[NODES][NODES];
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            dist[i][j] = costMatrix[i][j];
        }
    }
    for (int k = 0; k < NODES; k++) {
        for (int i = 0; i < NODES; i++) {
            for (int j = 0; j < NODES; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "Routing Table:\n";
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int costMatrix[NODES][NODES] = {
        {0, 7, INF, 5},
        {7, 0, 2, INF},
        {INF, 2, 0, 3},
        {5, INF, 3, 0}
    };
    distanceVector(costMatrix);
    return 0;
}
