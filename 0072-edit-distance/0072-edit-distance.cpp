class Solution {
public:
//     int fun(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
//         if(j < 0 && i < 0) return 0;
//         if(i < 0) return j+1; // insertions
//         if(j < 0) return i+1; // deletions

//         if(dp[i][j] != -1) return dp[i][j];

//         if(word1[i] == word2[j]){
//             return dp[i][j] = fun(i-1, j-1, word1, word2, dp);
//         }
//         return dp[i][j] = 1 + min(fun(i, j-1, word1, word2, dp), min(fun(i-1, j, word1, word2, dp), fun(i-1, j-1, word1, word2, dp)));
//     }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        // vector<vector<int>> dp(n1, vector<int> (n2, -1));
        // return fun(n1-1, n2-1, word1, word2, dp);

        // vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        // for(int row = 1; row<= n1; row++){
        //     dp[row][0] = row;
        // }
        // for(int col=1; col<= n2; col++){
        //     dp[0][col] = col;
        // }
        // for(int i=1; i<=n1; i++){
        //     for(int j = 1; j<=n2; j++){
        //         if(word1[i-1] == word2[j-1]){
        //              dp[i][j] = dp[i-1][j-1];
        //         }else{
        //             dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        //         }
        //     }
        // }
        // return dp[n1][n2];

        vector<int> dp(n2+1, 0);
        for(int col=1; col<= n2; col++){
            dp[col] = col;
        }
        for(int i=1; i<=n1; i++){
            vector<int> temp(n2+1, 0);
            temp[0] = i;
            for(int j = 1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]){
                     temp[j] = dp[j-1];
                }else{
                    temp[j] = 1 + min(temp[j-1], min(dp[j], dp[j-1]));
                }
            }
            dp = temp;
        }
        return dp[n2];
    }
};