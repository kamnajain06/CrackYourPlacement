class Solution {
public:
    // int fun(int i, int j, string &s, vector<vector<int>> &dp){
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == s[j]){
    //         if(i == j) return 1;
    //         else return dp[i][j] = 2 + fun(i+1, j-1, s, dp);
    //     }
    //     return dp[i][j] = max(fun(i+1, j, s, dp), fun(i, j-1, s, dp));
    // }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return fun(0, n-1, s, dp);
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Iterate over the length of the subsequence
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // Endpoint of the current subsequence

            if (s[i] == s[j]) {
                dp[i][j] = (len == 2) ? 2 : 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // The result is the length of the longest palindromic subsequence in the full string
    return dp[0][n - 1];
        
        
    }
};