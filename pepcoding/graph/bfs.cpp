#include <bits/stdc++.h>
using namespace std;

  void bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        queue<int> q;
        
       q.push(3);
       while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        vis[node] = 1;
        for( auto i : adj[node]){
            if(!vis[i]){
                q.push(i);
            }
        }
       } 
        
    }


void bfstraversal(int src, vector<int> adj[], vector<int> &vis){
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i : adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

int main() {

vector<int> adj[4];
adj[0].push_back(3);
adj[0].push_back(1);
adj[1].push_back(2);
adj[2].push_back(0);
adj[2].push_back(2);
adj[3].push_back(3);
//connect all element
 for(int i = 0; i < 4; i++){  
     adj[i].push_back(i);

// print list
for(int i = 0; i < 4; i++){
    cout<<i<<"->";
    for(auto j : adj[i]){
        cout<<j<<" ";
    }
    cout<<endl;
}


// vector<int> vis(4,0);
bfsOfGraph(4,adj);


    

    return 0;
}