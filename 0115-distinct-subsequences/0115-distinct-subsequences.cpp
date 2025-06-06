class Solution {
public:
    int f(int i, int j, string &s, string &t, int n1, int n2, vector<vector<int>> &dp){
        if(j == n2) return 1;
        if(i >= n1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        int skip = f(i+1, j, s, t, n1, n2, dp);
        if(s[i] == t[j]){
            take =  f(i+1, j+1, s, t, n1, n2, dp);
            return dp[i][j] = take + skip;
        }
        return dp[i][j] = skip;
    }
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(0, 0, s, t, n1, n2, dp);
    }
};