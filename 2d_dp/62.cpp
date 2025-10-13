class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int m, int n, int row, int col) {
        if (row > m - 1 || col > n - 1) {
            return 0;
        }
        if (row == m - 1 && col == n - 1) {
            return 1;
        }
        
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        dp[row][col] = dfs(m, n, row + 1, col) + dfs(m, n, row, col + 1);
        return dp[row][col];
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return dfs(m, n, 0, 0);
    }
};