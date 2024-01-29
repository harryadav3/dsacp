#include <bits/stdc++.h>
using namespace std;


vector<int> mergeksortedarrayinone(vector<vector<int>> &arr) {
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], {i, 0}});
    }
    while(!pq.empty()) {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int i = top.second.first;
        int j = top.second.second;
        if(j + 1 < arr[i].size()) {
            pq.push({arr[i][j + 1], {i, j + 1}});
        }
    }
    return ans;
}


//merge k sorted array into ione using min heap
vector<int> mregeksortedarray()

int main() {

    

    return 0;
}