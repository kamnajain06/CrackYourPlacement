class Solution {
public:
    // int f(int i, int j, int m , int n, vector<vector<int>>& grid, vector<vector<int>> &dp){
    //     if(i >=m || j >= n) return 1e9; 
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == m-1 && j == n-1) return grid[i][j];

    //     return dp[i][j] = grid[i][j] + min(f(i+1, j, m, n, grid, dp), f(i, j+1, m, n, grid, dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return f(0, 0, m, n, grid, dp);

        // vector<vector<int>> dp(m+1, vector<int> (n+1, 1e9));
        // dp[m-1][n-1] = grid[m-1][n-1];

        // for(int i=m-1; i>=0; i--){
        //     for(int j = n-1; j>=0; j--){
        //         if(i == m-1 && j == n-1) continue;
        //         dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
        //     }
        // }

        // return dp[0][0];

        vector<int> dp(n+1, 0);
        dp[n-1] = grid[m-1][n-1];
        for(int i=n-2; i>=0; i--){
            dp[i] = grid[m-1][i] +  dp[i+1];
        }

        for(int i=m-2; i>=0; i--){
            vector<int> curr(n+1, 1e9);
            for(int j = n-1; j>=0; j--){
                curr[j] = grid[i][j] + min(dp[j], curr[j+1]);
            }
            dp = curr;
        }

        return dp[0];
    }
};