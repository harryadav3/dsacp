#include <bits/stdc++.h>
using namespace std;

class Graph {

public:
    vector<vector<int>> adj;
    Graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v , bool bidir = true) {

        adj[u].push_back(v);

        if( bidir) {
            adj[v].push_back(u);

        }
    }

    //prnt Graph

    void printGraph() {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << "->";
            for (auto x : adj[i]) {
                cout << x << ",";
            }
            cout << endl;
        }
    }
    
};


void dfs( int node, vector<int> &vis, vector<vector<int>> &adj) {

    cout<<node<<"-> ";
    vis[node] = 1;

    for( auto i : adj[node]) {
       if( !vis[i]) {
        dfs(i, vis, adj);
       } 
    }
    
}
int main() {

    Graph g1(7);

    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,3);
    g1.addEdge(3,5);
    g1.addEdge(2,4);
    g1.addEdge(4,5);
    g1.addEdge(5,6);



    g1.printGraph();

vector<int> vis(7,0);
cout<<"DFS TRAVERSAL"<<endl;

cout<<"_________________________"<<endl<<endl;
    dfs(0, vis,g1.adj);
cout<<endl<<"__________________________"<<endl;
cout<<endl;
    return 0;
}