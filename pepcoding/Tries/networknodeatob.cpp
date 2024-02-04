#include <bits/stdc++.h>
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMin(int networkAnodes, vector<int>& networkAfrom, vector<int>& networkAto, 
                      int networkBnodes, vector<int>& networkBfrom, vector<int>& networkBto) {
        vector<vector<int>> adjA(networkAnodes + 1);
        vector<vector<int>> adjB(networkBnodes + 1);

        // Build adjacency lists for both networks
        for (int i = 0; i < networkAfrom.size(); ++i) {
            adjA[networkAfrom[i]].push_back(networkAto[i]);
            adjA[networkAto[i]].push_back(networkAfrom[i]);
        }

        for (int i = 0; i < networkBfrom.size(); ++i) {
            adjB[networkBfrom[i]].push_back(networkBto[i]);
            adjB[networkBto[i]].push_back(networkBfrom[i]);
        }

        // Find maximum depth in each network
        vector<int> depthA(networkAnodes + 1, 0);
        vector<int> depthB(networkBnodes + 1, 0);

        dfs(1, adjA, depthA, 0);
        dfs(1, adjB, depthB, 0);

        int result = INT_MAX;

        // Try connecting each node from network A to each node from network B
        for (int i = 1; i <= networkAnodes; ++i) {
            for (int j = 1; j <= networkBnodes; ++j) {
                int newDepth = max({depthA[i], depthB[j], depthA[i] + depthB[j] + 1});
                result = min(result, newDepth);
            }
        }

        return result;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& depth, int parent) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, adj, depth, node);
            }
        }
    }
};

int main() {
    // Example usage
    Solution solution;
    int networkAnodes = 3;
    vector<int> networkAfrom = {1, 1};
    vector<int> networkAto = {2, 3};
    int networkBnodes = 3;
    vector<int> networkBfrom = {1, 2};
    vector<int> networkBto = {2, 3};

    int result = solution.calculateMin(networkAnodes, networkAfrom, networkAto, networkBnodes, networkBfrom, networkBto);

    // Print the result
    cout << "Minimum Required Distance: " << result << endl;

    return 0;
}
