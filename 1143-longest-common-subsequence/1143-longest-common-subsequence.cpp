class Solution {
public:
//     int fun(int ind1, int ind2 ,string text1, string text2, vector< vector<int> > &dp ){
//         if(ind1 < 0 || ind2 < 0) return 0;

//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(text1[ind1] == text2[ind2]){
//             return dp[ind1][ind2] = 1 + fun(ind1-1, ind2-1, text1, text2, dp);
//         }
        
//         return dp[ind1][ind2] = max(fun(ind1-1, ind2, text1, text2, dp),fun(ind1, ind2-1, text1, text2, dp));
//     }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        // vector< vector<int> > dp(len1, vector<int> (len2, -1));
        // return fun(len1-1, len2-1, text1, text2, dp);

//         vector< vector<int> > dp(len1+1, vector<int> (len2+1, 0));
        
//         for(int i=1; i<=len1; i++){
//             for(int j=1; j<=len2; j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[len1][len2];

        vector< int > dp(len2+1,0);
        
        for(int i=1; i<=len1; i++){
            vector< int > temp(len2+1,0);
            for(int j=1; j<=len2; j++){
                if(text1[i-1] == text2[j-1]){
                    temp[j] = 1 + dp[j-1];
                }else{
                    temp[j] = max(dp[j], temp[j-1]);
                }
            }
            dp = temp;
        }
        return dp[len2];
    }
};