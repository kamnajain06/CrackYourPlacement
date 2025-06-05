class Solution {
public:
    // int f(int i, int j, string &s, int n,  vector<vector<int>> &dp){
    //     if(i >= j) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int op1 = 1 + min(f(i+1, j, s, n, dp) , f(i, j-1, s, n, dp));

    //     if(s[i] == s[j]){
    //         return dp[i][j] = min(f(i+1, j-1, s, n, dp), op1);
    //     }
    //     return dp[i][j] = op1;
    // }
    int minInsertions(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return f(0, n-1, s, n, dp);

        // vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        // for(int i=n-1; i>=0; i--){
        //     for(int j = 0; j < n; j++){
        //         if(i == j){
        //             dp[i][j] = 0;
        //             continue;
        //         }else if(i > j) continue;

        //         if(s[i] == s[j]) dp[i][j] = j-1 < n ? dp[i+1][j-1] : INT_MAX;
        //         else dp[i][j] = 1 + min((i + 1 < n ? dp[i+1][j] : 0)  , (j-1 >= 0 ? dp[i][j-1] : INT_MAX));
        //     }
        // }
        // return dp[0][n-1];

        vector<int> dp(n, 0);
        for(int i=n-1; i>=0; i--){
            vector<int> curr(n, INT_MAX);
            for(int j = 0; j < n; j++){
                if(i >= j) curr[j] = 0;
                else if(s[i] == s[j]) curr[j] = j-1 < n ? dp[j-1] : INT_MAX;
                else curr[j] = 1 + min((i + 1 < n ? dp[j] : 0)  , (j-1 >= 0 ? curr[j-1] : INT_MAX));
            }
            dp = curr;
        }
        return dp[n-1];
    }
};