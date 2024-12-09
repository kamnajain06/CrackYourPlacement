class Solution {
public:
    int dfs(int i, int j, int m , int n, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = dfs(i, j-1, m, n, dp);
        int down = dfs(i-1, j, m, n, dp);
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));

        // Memoization
        // return dfs(m-1, n-1, m, n, dp);

        // Tabulation
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};