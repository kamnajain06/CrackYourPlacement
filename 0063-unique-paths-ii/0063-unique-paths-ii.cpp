class Solution {
public:
    int dfs(int i, int j, int m , int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = dfs(i, j-1, m, n, dp, obstacleGrid);
        int down = dfs(i-1, j, m, n, dp, obstacleGrid);
        return dp[i][j] = (right)%2000000000 + (down)%2000000000;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Memoization
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return dfs(m-1, n-1, m, n, dp, obstacleGrid);
    }
};