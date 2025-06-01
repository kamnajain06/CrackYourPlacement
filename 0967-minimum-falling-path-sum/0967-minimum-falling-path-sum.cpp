class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp){
    //     if(i >= n || j >= n || j < 0) return 1e9;
    //     if(i == n-1) return matrix[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j] = matrix[i][j] + min({f(i+1, j, matrix, n, dp), f(i+1, j+1, matrix, n, dp) , f(i+1, j-1, matrix, n, dp)});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;

        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // for(int i = 0; i<n; i++){
        //     mini = min(f(0, i, matrix, n, dp), mini);
        // }
        // return mini;


        // vector<vector<int>> dp(n, vector<int> (n, 0));
        // dp[0] = matrix[0];

        // for(int i = 1; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         int val2 = (j + 1 < n ? dp[i-1][j+1] : 1e9);
        //         int val3 = ( j - 1 >= 0 ? dp[i-1][j-1] : 1e9);
        //         dp[i][j] = matrix[i][j] + min({dp[i-1][j], val2 , val3});
        //     }
        // }

        // for(int i = 0; i<n; i++){
        //     mini = min(dp[n-1][i], mini);
        // }

        // return mini;


        vector<int> dp(n, 0);
        dp = matrix[0];

        for(int i = 1; i<n; i++){
            vector<int> curr(n, 0);
            for(int j = 0; j<n; j++){
                int val2 = (j + 1 < n ? dp[j+1] : 1e9);
                int val3 = ( j - 1 >= 0 ? dp[j-1] : 1e9);
                curr[j] = matrix[i][j] + min({dp[j], val2 , val3});
            }
            dp = curr;
        }

        for(int i = 0; i<n; i++){
            mini = min(dp[i], mini);
        }

        return mini;
    }
};