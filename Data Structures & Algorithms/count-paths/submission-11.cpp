class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m-1, n-1, 0, 0, dp);
    }

    int dfs(int m, int n, int i, int j, vector<vector<int>>& dp){
        if (i > m || j > n) return 0;
        if(i == m && j == n){
            return 1;
        }
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = dfs(m, n, i+1, j, dp) + dfs(m, n, i, j+1, dp);
    }
};
