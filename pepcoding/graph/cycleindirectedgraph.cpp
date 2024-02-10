#include <bits/stdc++.h>
using namespace std;
// check the cycle in directed graph

bool dfs(int node , vector<bool> &vis, vector<bool> &dfsvis, vector<vector<int>> &adj) {
    vis[node] = true;
    dfsvis[node] = true;
    for( auto i : adj[node]){
        if(!vis[i]) {
            if(dfs(i, vis, dfsvis, adj)) return true;
        }
        else if( dfsvis[i]) {
            return true;
        }
    }
    dfsvis[node] = false;
    return false;
}




int main() {

    vector<vector<int>> adj(5);

   //create directed cyblic graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);


    vector<bool> vis(5, false);
vector<bool> dfsvis(5, false);

    for( int i = 0; i < 5; i++) {
        if(!vis[i]) {
            if(dfs(i, vis, dfsvis, adj)) {
                cout << "Cycle is present" << endl;
                return 0;
            }
        }
    }
    

    return 0;
}