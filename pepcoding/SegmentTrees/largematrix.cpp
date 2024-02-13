#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 20;

void updateGrid(vector<vector<int>>& grid, int N) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {  // Cell is already black
                continue;
            }
            int count_numbers = 0;
            for (auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] > 0) {
                    count_numbers++;
                    if (count_numbers >= 2) {
                        grid[i][j] = 0;  // Set black
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    updateGrid(grid, N);

    // Print the updated grid
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
