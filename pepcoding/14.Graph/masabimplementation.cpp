#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n ;
    vector<int> * arr;

    public:
    Graph(int n) {
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v, bool bidir = true) {
        arr[u].push_back(v);
        if (bidir) {
            arr[v].push_back(u);
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << "->";
            for (int node : arr[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }
};
int main() {

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3,false);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.print();

    return 0;
}