class Solution {
public:
    int f(int i, int j, int m , int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i >= m || j >= n) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];


        int down = f(i, j+1, m, n, obstacleGrid,  dp);
        int right = f(i+1, j, m, n, obstacleGrid,  dp);

        return dp[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return f(0, 0, m, n, obstacleGrid, dp);

        vector<vector<long long>> dp(m+1, vector<long long> (n+1, 0));
        if(obstacleGrid[m-1][n-1] == 0) dp[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = 1;
                    continue;
                }
                long long down = 0, right = 0;

                if(obstacleGrid[i][j] == 0){
                    down = dp[i+1][j];
                    right = dp[i][j+1];
                    dp[i][j] = down + right;
                }

            }
        }

        return dp[0][0];

        // if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        // vector<long long> dp(n+1, 0);
        // dp[n-1] = 1;

        // for(int i=m-1; i>=0; i--){
        //     vector<long long> curr(n+1, 0);
        //     for(int j = n-1; j>=0; j--){
        //         long long down = 0, right = 0;
        //         if(obstacleGrid[i][j] == 0){
        //             down = dp[j];
        //             right = curr[j+1];
        //             curr[j] = down + right;
        //         }
                
        //     }
        //     dp = curr;
        // }

        // return dp[0];
    }
};