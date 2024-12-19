class Solution {
public:
//     int minDistance(string word1, string word2) {
//         // int fun(int i, int j, string &word1, string &word2){
//     //     if(i == 0 && j == 0) return 0;

//     //     if(i == 0) return j;
//     //     else if(j == 0) return i;

//     //     if(word1[i] == word2[j]) return fun(i-1, j-1, word1, word2);
        
//     //     return 1 + min(fun(i-1, j, word1, word2), fun(i, j-1, word1, word2));

//     }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        // return fun(n1-1, n2-1, word1, word2);


        // vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));

        // for(int row=0; row<=n1; row++){
        //     dp[row][0] = row;
        // }
        // for(int col=0; col<=n2; col++){
        //     dp[0][col] = col;
        // }

        // for(int row=1; row<=n1; row++){
        //     for(int col=1 ; col <= n2; col++){
        //         if(word1[row-1] == word2[col-1]){ // 1-based indexing;
        //             dp[row][col] = dp[row-1][col-1];
        //         }else{
        //             dp[row][col] = 1 + min(dp[row-1][col], dp[row][col-1]);
        //         }
        //     }
        // }
        // return dp[n1][n2];

        vector<int> dp(n2+1,0);

        for(int col=0; col<=n2; col++){
            dp[col] = col;
        }

        for(int row=1; row<=n1; row++){
            vector<int> temp(n2+1,0);
            temp[0] = row;
            for(int col=1 ; col <= n2; col++){
                if(word1[row-1] == word2[col-1]){ // 1-based indexing;
                    temp[col] = dp[col-1];
                }else{
                    temp[col] = 1 + min(dp[col], temp[col-1]);
                }
            }
            dp = temp;
        }
        return dp[n2];
    }
};