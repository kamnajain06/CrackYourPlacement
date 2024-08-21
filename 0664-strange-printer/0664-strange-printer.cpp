class Solution {
public:
    int solve(int i, int j, string s, vector<vector<int>> &dp){
        if (i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

//         basic
        int minTurns = 1 + solve(i+1, j, s, dp);

//         greedy
        for(int k=i+1; k<=j; k++){
            if(s[k] == s[i]) minTurns = min(minTurns, solve(i,k-1,s,dp)+solve(k+1,j,s,dp));
        }

        return dp[i][j] = minTurns;
    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        return solve(0,n-1,s,dp);
    }
};