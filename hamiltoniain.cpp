#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 20;

void printPath(const vector<int>& path) {
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
}

bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& path, int pos) {
    // Check if vertex v can be added to the path
    if (graph[path[pos - 1]][v] == 0) {
        return false; // There's no edge between the last vertex in the path and vertex v
    }

    // Check if vertex v is already in the path
    for (int vertex : path) {
        if (vertex == v) {
            return false;
        }
    }

    return true;
}

bool hamiltonianCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    int V = graph.size();

    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if there's an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            printPath(path);
            return true;
        } else {
            return false;
        }
    }

    // Try different vertices as the next candidate in the path
    for (int v = 1; v < V; ++v) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            // Recur to construct the rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1)) {
                return true;
            }
            // If adding vertex v doesn't lead to a solution, backtrack
            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> path(V, -1); // Initialize path array with -1

    // The first vertex is always 0
    path[0] = 0;

    // Find Hamiltonian cycle using backtracking
    return hamiltonianCycleUtil(graph, path, 1);
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    if (!hamiltonianCycle(graph)) {
        cout << "Hamiltonian path does not exist" << endl;
    }

    return 0;
}
