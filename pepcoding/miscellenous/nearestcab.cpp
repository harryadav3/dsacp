#include <bits/stdc++.h>
using namespace std;

class Cabcompare {
    public:
    bool operator()(vector<int> a, vector<int> b) {
        return (abs(a[0]) + abs(a[1])) > (abs(b[0]) + abs(b[1]));
    }
};

int main() {

    vector<vector<int>> arr = {{1,2},{-1,3},{-1,-2},{1,-3},{2,3},{-2,-3},{-2,2},{2,-2}};

    /* 

    bool compare( Cab a , Cab b){
        return (abs(a.x) + abs(a.y)) > (abs(b.x) + abs(b.y));
    }
    int priority_queue<int> pq;

    sort(v.begin(), v.end(), compare);

    
    */
    
    priority_queue<int, vector<vector<int>>  , Cabcompare> pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], arr[i][1]});
    }

    while (!pq.empty()) {
        cout << pq.top()[0] << " " << pq.top()[1] << endl;
        pq.pop();
    }
    return 0;
}