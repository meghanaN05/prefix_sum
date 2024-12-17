#include <iostream>
#include <vector>

using namespace std;

// Function to preprocess the grid and compute the prefix sum array
vector<vector<int>> computePrefixSum(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> prefix(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            prefix[i][j] = grid[i][j] == 0 ? 1 : 0;
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }
    return prefix;
}

// Function to calculate the number of 0-cost cells in a subgrid
int getZeroCostCount(const vector<vector<int>>& prefix, int A, int B, int C, int D) {
    int count = prefix[C][D];
    if (A > 0) count -= prefix[A - 1][D];
    if (B > 0) count -= prefix[C][B - 1];
    if (A > 0 && B > 0) count += prefix[A - 1][B - 1];
    return count;
}

int main() {
    int rows, cols, q;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    // Preprocess the grid to compute the prefix sum array
    vector<vector<int>> prefix = computePrefixSum(grid);

    // Read the number of queries
    cin >> q;

    while (q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // Convert to 0-based indexing
        A--; B--; C--; D--;

        // Calculate the number of 0-cost cells in the subgrid
        int zeroCostCells = getZeroCostCount(prefix, A, B, C, D);

        // Output the result
        if (zeroCostCells > 0) {
            cout << 0 << endl; // Cost is 0
        } else {
            cout << 1 << endl; // Cost is 1
        }
    }

    return 0;
}
