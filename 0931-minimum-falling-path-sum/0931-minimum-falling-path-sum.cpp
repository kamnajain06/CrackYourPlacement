class Solution {
public:
    // int fun(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(j < 0 || j >= n) return INT_MAX;
    //     if(i == n-1) return matrix[i][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = fun(i+1, j, n, matrix, dp);
    //     int left = fun(i+1, j-1, n, matrix, dp);
    //     int right = fun(i+1, j+1, n, matrix, dp);
    //     return dp[i][j] = matrix[i][j] + min(down, min(left, right));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // MEMOIZATION
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        // int ans = INT_MAX;

        // for(int j=0; j<n; j++){
        //     ans = min(ans, fun(0,j, n, matrix, dp));
        // }
        // return ans;

        // // TABULATION
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        // for(int j=0; j<n; j++){
        //     dp[0][j] = matrix[0][j];
        // }
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         int up = dp[i-1][j];
        //         int left = j - 1 >= 0 ? dp[i-1][j-1] : INT_MAX;
        //         int right = j + 1 < n ? dp[i-1][j+1] : INT_MAX; 
        //         dp[i][j] = matrix[i][j] + min(up, min(left,right));
        //     }
        // }
        // int ans = INT_MAX;
        // for(auto it:dp[n-1]){
        //     ans = min(ans, it);
        // }
        // return ans;

        // SPACE OPT
        vector<int> dp(n, 0);
        for(int j=0; j<n; j++){
            dp[j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                int up = dp[j];
                int left = j - 1 >= 0 ? dp[j-1] : INT_MAX;
                int right = j + 1 < n ? dp[j+1] : INT_MAX; 
                temp[j] = matrix[i][j] + min(up, min(left,right));
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for(auto it:dp){
            ans = min(ans, it);
        }
        return ans;
    }
};