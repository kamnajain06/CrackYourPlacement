class Solution {
public:
    // int fun(int i, int j, string &s){
    //     if(i > j) return 0;
    //     if(s[i] == s[j]){
    //         return fun(i+1, j-1, s);
    //     }
    //     return 1 + min( fun(i+1, j, s), fun(i, j-1, s));
    // }
    int fun(int i, int j, string &s, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            if(i == j) return 1;
            else return dp[i][j] = 2 + fun(i+1, j-1, s, dp);
        }
        return dp[i][j] = max(fun(i+1, j, s, dp), fun(i, j-1, s, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        // return fun(0, n-1, s);
        int val = fun(0, n-1, s, dp);
        return n-val;
    }
};