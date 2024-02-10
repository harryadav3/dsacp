#include <bits/stdc++.h>
using namespace std;

class Graph {

    public: 
    vector<vector<int>> adjList;

        //constructor
       Graph(int n ) {
            adjList.resize(n);
       }

      void   addEdge(int u, int v , bool bidir = true) {
            adjList[u].push_back(v);
            if (bidir) {
                adjList[v].push_back(u);
            }
        }

        void print() {
            for ( int i =0; i < adjList.size(); i++ ) {
                cout << i << "->";
                for (int node : adjList[i]) {
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
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.print();
    

    return 0;
}