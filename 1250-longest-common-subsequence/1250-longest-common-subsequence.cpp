class Solution {
public:
    // int f(int i, int j, string &text1, string &text2, int &n1, int &n2, vector<vector<int>> &dp){
    //     if(i >= n1 || j >= n2) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int skip = f(i, j+1, text1, text2, n1, n2, dp);
    //     int skip1 = f(i+1, j, text1, text2, n1, n2, dp);
    //     int take = 0;

    //     if(text1[i] == text2[j]){
    //         take = 1 + f(i+1, j+1, text1, text2, n1, n2, dp);
    //     }
    //     return dp[i][j] = max({skip, skip1, take});
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        // vector<vector<int>> dp(n1, vector<int> (n2, -1));
        // return f(0, 0, text1, text2, n1, n2, dp);


        // vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        // for(int i=n1-1; i>=0; i--){
        //     for(int j = n2-1; j>=0; j--){
        //         int skip = dp[i][j+1];
        //         int skip1 = dp[i+1][j];
        //         int take = 0;

        //         if(text1[i] == text2[j]){
        //             take = 1 + dp[i+1][j+1];
        //         }
        //         dp[i][j] = max({skip, skip1, take});
        //     }
        // }
        // return dp[0][0];

        vector<int> dp(n2+1, 0);
        for(int i=n1-1; i>=0; i--){
            vector<int> curr(n2+1, 0);
            for(int j = n2-1; j>=0; j--){
                int skip = curr[j+1];
                int skip1 = dp[j];
                int take = 0;

                if(text1[i] == text2[j]){
                    take = 1 + dp[j+1];
                }
                curr[j] = max({skip, skip1, take});
            }
            dp = curr;
        }
        return dp[0];
    }
};