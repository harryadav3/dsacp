#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, int i, int j, vector<vector<int>> &matrix)
{

    if (i < 0 || j < 0 || i > m || j > n)
        return INT_MAX;

    if (i == m)
        return matrix[i][j];
    // write the logic hari to claculate the min path sum ld , d, rd with out overflowing the matrix

    int ld = solve(m, n, i + 1, j - 1, matrix);
    int d = solve(m, n, i + 1, j, matrix);
    int rd = solve(m, n, i + 1, j + 1, matrix);

    return min(ld, min(d, rd));
}
int main()
{
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
     int m = matrix.size();
    int n = matrix[0].size();

    int ans = INT_MAX;
    for (int p = 0; p < n; p++)
    {
        ans = min(ans, solve(m - 1, n - 1, 0, p, matrix));
    }
    cout << ans << endl;
    return 0; 
}
