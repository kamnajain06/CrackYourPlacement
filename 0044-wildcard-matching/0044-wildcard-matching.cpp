class Solution {
public:
    // bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
    //     if (i < 0 && j < 0)
    //         return true;
    //     if (i < 0) {
    //         while (j >= 0 && p[j] == '*')
    //             j--;
    //         return j < 0;
    //     }
    //     if (j < 0)
    //         return false;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s[i] == p[j] || p[j] == '?') {
    //         return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
    //     } else if (p[j] == '*') {
    //         return dp[i][j] =
    //                    fun(i, j - 1, s, p, dp) || fun(i - 1, j, s, p, dp);
    //     }
    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return fun(n-1, m-1, s, p, dp);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // dp[0][0] = true;
        // for (int col = 1; col <= m; col++) {
        //     if (p[col - 1] == '*')
        //         dp[0][col] = true;
            // else break;
        // }
        // for (int row = 1; row <= n; row++) {
        //     dp[row][0] = false;
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         } else if (p[j - 1] == '*') {
        //             dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        //         } else {
        //             dp[i][j] = false;
        //         }
        //     }
        // }
        // return dp[n][m];

        vector<int> dp(m + 1, false);
        dp[0] = true;
        for(int col=1; col<=m; col++){
            if(p[col-1] == '*') dp[col] = true;
            else break;
        }
        for (int i = 1; i <= n; i++) {
            vector<int> temp(m + 1, -1);
            temp[0] = false;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    temp[j] = dp[j - 1];
                } else if (p[j - 1] == '*') {
                    temp[j] = temp[j - 1] || dp[j];
                } else {
                    temp[j] = false;
                }
            }
            dp = temp;
        }
        return dp[m];
    }
};