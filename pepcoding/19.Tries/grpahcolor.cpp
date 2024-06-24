#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of different color codes
long long countColorCodes(int N, int C) {
    // Create two vectors to store the count of color codes for two rows
    vector<long long> dp0(C + 1, 0);
    vector<long long> dp1(C + 1, 0);

    // Initialize the base cases
    dp0[1] = dp1[1] = N;

    // Iterate through columns
    for (int j = 2; j <= C; ++j) {
        // Calculate the count for each cell in the current column based on the previous column
        dp0[j] = dp1[j - 1];
        dp1[j] = dp0[j - 1];
    }

    // Return the total count of color codes
    return dp0[C] + dp1[C];
}

int main() {
    // Input N and C
    int N, C;
    cin >> N >> C;

    // Calculate and output the result
    cout << countColorCodes(N, C) << endl;

    return 0;
}