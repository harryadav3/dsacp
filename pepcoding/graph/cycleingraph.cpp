#include <bits/stdc++.h>
using namespace std;


bool dfs(int node , int par, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[node] = true;
    for( auto i : adj[node]) {
        if(!vis[i]) {
            if(dfs(i, node, vis, adj)) return true;
        }
        else if( node != par) {
            return true;
        }
    }

     return false;
}

// bool bfs(int node, vector<bool> &vis, vector<vector<int>> &adj) {

//     vis[node] = true;

// }

bool masabbfs(int node , vector<bool> &vis, vector<vector<int>> &adj) {

    vis[node] = true;
    vector<int> parent;
    parent[node] = -1;
    queue<int> q;

    q.push(node);

    while ( !q.empty()){

        int f = q.front() ; q.pop();

        for( auto i : adj[f]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
                parent[i] = f;
            }
            else if( parent[f] != i) {
                return true;
            }
        } 
    }
    return false;
}

int main() {

    vector<vector<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    vector<bool> vis(5, false);

    for (int i = 0 ; i<5; i++ ) {
        
        if(!vis[i]){
        //    if( dfs(i, -1, vis, adj)){
        //      cout<<"cycle found\n"; return 0;
        // }
           if( masabbfs(i,  vis, adj)){
             cout<<"cycle found\n"; return 0;
        }
        }
    }

    cout<<"cycle not found\n";


    

    return 0;
}