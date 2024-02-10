// find the minimum path in a graph using djikstra


#include <bits/stdc++.h>
using namespace std;

//write a djikstra algorithm to find the minimum path in a graph from source to destination

int solve(vector<vector<int>> &graph, int sr, int sc, int dr, int dc) {
    int n = graph.size();
    int m = graph[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

// priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>> pq;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    
    pq.push({0, {sr, sc}});
    dist[sr][sc] = 0;

    while(!pq.empty()) {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if(visited[u][v]) {
            continue;
        }

        visited[u][v] = true;

        if(u == dr && v == dc) {
            return dist[u][v];
        }

        /// in all 8 directions using [ -1, 0, 1 array]

        int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
        int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1};

        for(int i = 0; i < 8; i++) {
            int x = u + dx[i];
            int y = v + dy[i];

            if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && dist[x][y] > dist[u][v] + graph[u][v]) {
                dist[x][y] = dist[u][v] + graph[u][v];
                pq.push({dist[x][y], {x, y}});
            }
        }


    }


    return -1;


}







int main() {

    // vector<vector<int>> graph {
    //     { 0, 1, 4, 1, 0, 12 },
    //     { 1, 0, 4, 2, 7, 9 },
    //     { 4, 4, 0, 3, 5, 5 },
    //     { 0, 2, 3, 0, 4, 6 },
    //     { 9, 7, 5, 4, 0, 7 },
    //     { 0, 2, 3, 6, 7, 0 }
    // };

    vector<vector<int>> graph {
        { 0, 1, 4 },
        { 1, 0, 4 },
        { 4, 4, 0  },
        { 0, 2, 3  },
    };


    int sr= 0, sc = 1, dr = 3, dc = 2;


    cout<<solve(graph, sr, sc, dr, dc)<<endl;


    return 0;
}