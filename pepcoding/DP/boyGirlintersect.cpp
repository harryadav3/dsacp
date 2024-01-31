#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dpBoy(n, vector<int>(m, 0));
    vector<vector<int>> dpGirl(n, vector<int>(m, 0));

    dpBoy[0][0] = grid[0][0];
    dpGirl[n - 1][0] = grid[n - 1][0];

    for (int i = 1; i < n; i++) {
        dpBoy[i][0] = dpBoy[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < m; j++) {
        dpBoy[0][j] = dpBoy[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; i++)  {
        for (int j = 1; j < m; j++) {
            dpBoy[i][j] = max(dpBoy[i - 1][j], dpBoy[i][j - 1]) + grid[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        dpGirl[i][0] = dpGirl[i + 1][0] + grid[i][0];
    }
    for (int j = 1; j < m; j++)
    {
        dpGirl[n - 1][j] = dpGirl[n - 1][j - 1] + grid[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j < m; j++)
        {
            dpGirl[i][j] = max(dpGirl[i + 1][j], dpGirl[i][j - 1]) + grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
            cout << dpBoy[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dpGirl[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 1, 4, 6},
        {6, 8, 7, 2, 3},
        {4, 3, 2, 1, 6},
        {11, 10, 8, 5, 4},
        {12, 15, 6, 3, 7}};

    int maxCoinsCollected = maxCoins(grid);
    cout << "Maximum coins collected: " << maxCoinsCollected << endl;

    return 0;
}