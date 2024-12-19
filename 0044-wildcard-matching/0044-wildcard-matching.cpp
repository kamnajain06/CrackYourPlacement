class Solution {
public:
    bool fun(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0){
            while(j >= 0 && p[j] == '*') j--;
            return j < 0;
        }
        if (j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = fun(i-1, j-1, s, p, dp);
        }else if(p[j] == '*'){
            return dp[i][j] =fun(i, j-1, s, p, dp) || fun(i-1, j, s, p, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n-1, m-1, s, p, dp);
    }
};