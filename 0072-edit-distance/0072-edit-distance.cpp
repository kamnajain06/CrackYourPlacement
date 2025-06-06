class Solution {
public:
    int f(int i, int j, int n1, int n2, string &word1, string &word2, vector<vector<int>> &dp){
        if(j == n2) return n1-i;
        if(i >= n1) return n2-j;
        if(dp[i][j] != -1) return dp[i][j];

        int move = f(i+1, j+1, n1, n2, word1, word2, dp);

        if(word1[i] == word2[j]){
            return dp[i][j] = move;
        }
        int del = f(i+1, j, n1, n2, word1, word2, dp);
        int ins = f(i, j+1, n1, n2, word1, word2, dp);

        return dp[i][j] = 1 + min({ins, del, move});

    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(0, 0, n1, n2, word1, word2, dp);
    }
};