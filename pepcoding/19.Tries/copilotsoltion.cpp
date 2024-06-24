#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMin(int networkA_nodes, vector<int>& networkA_from, vector<int>& networkAto, int networkBnodes, vector<int>& networkBfrom, vector<int>& networkBto) {
        vector<vector<int>> adjA(networkA_nodes + 1), adjB(networkBnodes + 1);
        for (int i = 0; i < networkA_nodes - 1; ++i) {
            adjA[networkA_from[i]].push_back(networkAto[i]);
            adjA[networkAto[i]].push_back(networkA_from[i]);
        }
        for (int i = 0; i < networkBnodes - 1; ++i) {
            adjB[networkBfrom[i]].push_back(networkBto[i]);
            adjB[networkBto[i]].push_back(networkBfrom[i]);
        }
        vector<int> depthA(networkA_nodes + 1), depthB(networkBnodes + 1);
        dfs(1, adjA, depthA, 0);
        dfs(1, adjB, depthB, 0);
        int diameterA = *max_element(depthA.begin(), depthA.end());
        int diameterB = *max_element(depthB.begin(), depthB.end());
        int newDiameter = (diameterA + 1) / 2 + (diameterB + 1) / 2 + 1;
        return max(max(diameterA, diameterB), newDiameter);
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
    Solution solution;
    int networkA_nodes = 3;
    vector<int> networkA_from = {1, 1};
    vector<int> networkAto = {2, 3};
    int networkBnodes = 3;
    vector<int> networkBfrom = {1, 2};
    vector<int> networkBto = {2, 3};

    int result = solution.calculateMin(networkA_nodes, networkA_from, networkAto, networkBnodes, networkBfrom, networkBto);
    cout << "The minimum possible required distance is: " << result << endl;

    return 0;
}