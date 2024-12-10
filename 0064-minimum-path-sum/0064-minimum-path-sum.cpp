class Solution {
public:
    // int fun(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp){
    //     if(i == 0 && j == 0) return grid[0];
    //     if(i < 0 || j < 0) return INT_MAX;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j] =  grid[i][j] + min(fun(i-1, j, m, n, grid, dp), fun(i, j-1, m, n, grid, dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector< vector<int> > dp(m, vector<int> (n, -1));
        // return fun(m-1, n-1, m, n, grid, dp);


        // for(int i=0; i<m ; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == 0 && j == 0) dp[i][j] = 1;
        //         else{
        //             int up = i - 1 >= 0 ? grid[i][j] + dp[i-1][j] : INT_MAX;
        //             int left = j-1 >= 0 ? grid[i][j] + dp[i][j-1] : INT_MAX;

        //             dp[i][j] = min(up, left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int> dp(n, 0);
        // dp[0] = grid[0][0];
        for(int i=0; i<m ; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) temp[j] = grid[0][0];
                else{
                    int up = i - 1 >= 0 ? grid[i][j] + dp[j] : INT_MAX;
                    int left = j-1 >= 0 ? grid[i][j] + temp[j-1] : INT_MAX;

                    temp[j] = min(up, left);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};