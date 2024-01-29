#include <bits/stdc++.h>
using namespace std;

/*
solve this question 
A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived

these constraints
1 <= target, startFuel <= 109
0 <= stations.length <= 500
1 <= positioni < positioni+1 < target
1 <= fueli < 109.
*/

 //solve above question with regardgint to manage the constraint
    //1 <= target, startFuel <= 109
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            if(dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }


int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int i = 0;
        int ans = 0;
        while(startFuel < target) {
            while(i < n && stations[i][0] <= startFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) {
                return -1;
            }
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }


// int masabsolution(int t, int s , vector<vector<int>>&stations){

//     sort(stations.begin(), stations.end());
//     priority_queue<int> pq;
//     int ans ;

//     for( auto &st: stations){
//         if( s - st[0] < 0){
//             while( !pq.empty() && s-st[0] < 0){

//                 s += pq.top(); 
//                 ans++;
//                 pq.pop();
//             }
//             if(pq.empty() && s - st[0] < 0){
//                     return -1;
//             }
//         }
//     }
//     pq.push(stations[1]);

//     while(!pq.empty() && s - t < 0){
//         s += pq.top();
//         pq.pop();
//         ans++;
//     }

//     if()

// }
int main() {

    

    return 0;
}