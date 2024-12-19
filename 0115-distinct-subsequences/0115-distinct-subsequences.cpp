class Solution {
public:
    // int fun(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    //     if(j < 0) return 1;
    //     if(i < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]){
    //         return dp[i][j] = fun(i-1, j-1, s, t, dp) + fun(i-1, j, s, t, dp);
    //     }
    //     return dp[i][j] = fun(i-1, j, s, t, dp);
    // }
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        // vector<vector<int>> dp(n1, vector<int> (n2, -1));
        // return fun(n1-1, n2-1, s, t, dp);

        // vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        // for(int row = 0; row <= n1; row++){
        //     dp[row][0] = 1;
        // }

        // for(int i=1; i<=n1; i++){
        //     for(int j=1; j<=n2; j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n1][n2];
        vector<double> dp(n2+1, 0);
        dp[0] = 1;

        for(int i=1; i<=n1; i++){
            vector<double> temp(n2+1, 0);
            temp[0] = 1;
            for(int j=1; j<=n2; j++){
                if(s[i-1] == t[j-1]){
                    temp[j] = dp[j-1] + dp[j];
                }else{
                    temp[j] = dp[j];
                }
            }
            dp = temp;
        }
        return (int)dp[n2];
    }
};