//write a template for of wieghted graph


#include <bits/stdc++.h>
#include <string>
using namespace std;


template <typename T>
class Graph {
    int n;
    unordered_map<T, list<pair<T, int>>> adjList;
     

public:

    void addEdge(T u ,T v, int wt, bool bidir = true) {
        adjList[u].push_back(make_pair(v, wt));
        if (bidir) {
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjList() {
        for (auto city : adjList) {
            cout << city.first << "->";
            for (auto connectedCity : city.second) {
                cout << "(" << connectedCity.first << "," << connectedCity.second << ")";
            }
            cout << endl;
        }
    }

    void bfsSPA(T src){
        unordered_map<T, int> dist;
        for(auto i : adjList){
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        queue<T> q;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto i : adjList[node]){
                if(dist[i.first] == INT_MAX){
                    dist[i.first] = dist[node] + i.second;
                    q.push(i.first);
                }
            }
        }
        for(auto i : dist){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
};




int main() {
    Graph<string> g;
    
    g.addEdge("Amritsar","Delhi", 1);
    g.addEdge("Amritsar","Jaipur", 4);
    g.addEdge("Delhi","Jhansi", 2);
    g.addEdge("Delhi","Lucknow", 3);
    g.addEdge("Delhi","Mumbai", 8);

    g.bfsSPA("Amritsar");
    g.printAdjList();

     
    return 0;
}