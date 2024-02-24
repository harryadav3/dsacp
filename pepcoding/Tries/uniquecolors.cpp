/*
Unique Colors

Problem Statement

There are N boxes with each box i has value V[i]. These boxes are colorless initially and you are supposed to paint each box with some color. But as always, there are a few conditions which you will follow while painting the boxes.

1) For 2 boxes i and j (i<j) with color c1, there is no box k (i<k<j) which doesn't have color c1.
2) For all boxes with same color, the difference between minimum and maximum value of box is no more than S.

Colors are costly and using so many different colors might make it look ugly. What is the minimum number of colors you will need to paint all the boxes while satisfying the above condition?


Input Format:

The first line contains two space-separated integers N, S (1 ≤ S ≤ 10^5, 0 ≤ S ≤ 10^9).

The second line contains N integers V[i] separated by spaces ( -10^9 ≤ V[i] ≤ 10^9).

Output Format:

Output one integer that is minimum number of colors needed.


Sample Input 1:

7 2
1 3 1 2 4 1 2

Sample Output 1:

3

Explanation:

For the first sample, we can use 3 colors with following possible arrangement: Color1 = [1, 3, 1, 2], Color2 = [4], Color3 = [1, 2].


Sample Input 2:

10 3
1 1 1 1 1 5 6 7 8 9

Sample Output 2:

3
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>


using namespace std;


// Function to calculate the number of different color codes

long long countColorCodes(int N, int S, vector<int> &V) {
    // Sort the box values
    sort(V.begin(), V.end());
    
    // Create a map to store the color codes
    map<int, vector<int>> colorCodes;
    
    // Iterate through the boxes
    for (int i = 0; i < N; ++i) {
        // Get the current box value
        int boxValue = V[i];
        
        // Iterate through the color codes
        for (auto &color : colorCodes) {
            // Get the last box value for the current color
            int lastBoxValue = color.second.back();
            
            // Check if the difference between the current box value and the last box value is less than or equal to S
            if (boxValue - lastBoxValue <= S) {
                // Add the current box value to the current color
                color.second.push_back(boxValue);
                
                // Break the loop
                break;
            }
        }
        
        // If the current box value is not added to any color, create a new color
        if (colorCodes.find(boxValue) == colorCodes.end()) {
            colorCodes[boxValue] = {boxValue};
        }
    }
    
    // Return the total count of color codes
    return colorCodes.size();
}


int main() {
    // Input N and S
    int N, S;
    cin >> N >> S;
    
    // Input the box values
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    
    // Calculate and output the result
    cout << countColorCodes(N, S, V) << endl;
    
    return 0;
}


// Time Complexity: O(NlogN)