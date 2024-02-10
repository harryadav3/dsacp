#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    unordered_map<string,list<string>> adjList;

public:
    // Graph(int n, list<string> cities) {
    //     this->n = n;
    //     for (string city : cities) {
    //         adjList[city] = list<string>();
    //     }
    // }
    void addEdge(string u ,string v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto city : adjList) {
            cout << city.first << "->";
            for (string connectedCity : city.second) {
                cout << connectedCity << ",";
            }
            cout << endl;
        }
    }
};


int main() {

    
    Graph g;
    
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Jhansi");
    g.addEdge("Delhi","Lucknow");
    g.addEdge("Delhi","Mumbai");
    g.printAdjList();


    return 0;
}