class Solution {
public:
    // bool f(int i, int j, int n1, int n2, string& s, string& p,
    //        vector<vector<int>>& dp) {
    //     if (i == n1) {
    //         while (j != n2) {
    //             if (p[j++] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if (i == n1 && j == n2)
    //         return true;
    //     if (i >= n1 || j >= n2)
    //         return false;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     bool val = false;

    //     if (s[i] == p[j] || p[j] == '?') {
    //         val = val || f(i + 1, j + 1, n1, n2, s, p, dp);
    //     } else if (p[j] == '*') {
    //         val = val || f(i + 1, j, n1, n2, s, p, dp) ||
    //               f(i + 1, j + 1, n1, n2, s, p, dp) ||
    //               f(i, j + 1, n1, n2, s, p, dp);
    //     }
    //     return dp[i][j] = val;
    // }
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();
        // if(n1 == 0) return true;
        // vector<vector<int>> dp(n1, vector<int> (n2, -1));
        // return f(0, 0, n1, n2, s, p, dp);

        // vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        // dp[n1][n2] = true;
        // for(int j = n2-1; j >=0; j--){
        //     if (p[j] == '*'){
        //         dp[n1][j] = true;
        //     }else break;
        // }
        // for (int i = n1-1; i >= 0; i--) {
        //     for (int j = n2-1; j >= 0; j--) {
        //         bool val = false;
        //         if (s[i] == p[j] || p[j] == '?') {
        //             val = val || dp[i + 1][j + 1];
        //         } else if (p[j] == '*') {
        //             val = val || dp[i + 1][j] || dp[i + 1][j + 1] || dp[i][j
        //             + 1];
        //         }
        //         dp[i][j] = val;
        //     }
        // }
        // return dp[0][0];

        vector<bool> dp(n2 + 1, false);
        dp[n2] = true;
        for (int j = n2 - 1; j >= 0; j--) {
            if (p[j] == '*') {
                dp[j] = true;
            } else
                break;
        }
        for (int i = n1 - 1; i >= 0; i--) {
            vector<bool> curr(n2 + 1, false);
            for (int j = n2 - 1; j >= 0; j--) {
                bool val = false;
                if (s[i] == p[j] || p[j] == '?') {
                    val = val || dp[j + 1];
                } else if (p[j] == '*') {
                    val = val || dp[j] || dp[j + 1] || curr[j + 1];
                }
                curr[j] = val;
            }
            dp = curr;
        }
        return dp[0];
    }
};