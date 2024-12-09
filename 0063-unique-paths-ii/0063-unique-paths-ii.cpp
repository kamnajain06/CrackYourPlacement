class Solution {
public:
    // int dfs(int i, int j, int m , int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
    //     if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int right = dfs(i, j-1, m, n, dp, obstacleGrid);
    //     int down = dfs(i-1, j, m, n, dp, obstacleGrid);
    //     return dp[i][j] = (right)%2000000000 + (down)%2000000000;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // // Memoization
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return dfs(m-1, n-1, m, n, dp, obstacleGrid);
        
        // // Tabulation
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
        //         else if(i == 0 && j == 0) dp[i][j] = 1;
        //         else{
        //             int left = j-1 >= 0 ? dp[i][j-1]%2000000000 : 0;
        //             int right = i-1 >= 0 ? dp[i-1][j]%2000000000 : 0;
        //             dp[i][j] = (left + right)%2000000000;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=0; i<m; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) temp[j] = 0;
                else{
                    int left = j-1 >= 0 ? temp[j-1] : 0;
                    temp[j] = left + dp[j];
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};