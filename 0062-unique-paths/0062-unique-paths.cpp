class Solution {
public:
    // int dfs(int i, int j, int m , int n, vector<vector<int>> &dp){
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int right = dfs(i, j-1, m, n, dp);
    //     int down = dfs(i-1, j, m, n, dp);
    //     return dp[i][j] = right + down;
    // }
    int uniquePaths(int m, int n) {
        // Memoization
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return dfs(m-1, n-1, m, n, dp);

        // // Tabulation
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == 0 && j == 0) dp[i][j] = 0;
        //         else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=0; i<m; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                int left = j-1 >= 0 ? temp[j-1] : 0;
                temp[j] = left + dp[j];
            }
            dp = temp;
        }
        return dp[n-1];
    }
};