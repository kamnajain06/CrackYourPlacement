class Solution {
public:
    int fun(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(j < 0 && i < 0) return 0;
        if(i < 0) return j+1; // insertions
        if(j < 0) return i+1; // deletions

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = fun(i-1, j-1, word1, word2, dp);
        }
        return dp[i][j] = 1 + min(fun(i, j-1, word1, word2, dp), min(fun(i-1, j, word1, word2, dp), fun(i-1, j-1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return fun(n1-1, n2-1, word1, word2, dp);
    }
};