#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n ;
    vector<pair<int,int>> *adj;

    Graph(int n) {
        this->n = n;
        adj = new vector<pair<int,int>>[n];

    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int djikstra(int src, int dest) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(auto x : adj[u]) {
                int v = x.first;
                int weight = x.second;
                if(dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[dest];
    }
}

int main() {

    

    return 0;
}