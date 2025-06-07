class Solution {
public:
    // int f(int i, int buy, vector<int> &prices, int n, int cnt, vector<vector<vector<int>>> &dp){
    //     if(cnt > 2) return 0;
    //     if(i >= n) return 0;
    //     if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];
    //     int op1 = f(i+1, buy, prices, n, cnt, dp);
    //     if(buy){
    //         return dp[i][buy][cnt] = max(-prices[i] + f(i+1, buy-1, prices, n, cnt, dp) , op1);
    //     }
    //     return dp[i][buy][cnt] = max(prices[i] + f(i+1, buy + 1, prices, n, cnt + 1, dp) , op1);
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        // return f(0, 1, prices, n, 1, dp);

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (4, 0)));
        // for(int i= n-1; i>=0; i--){
        //     for(int j = 0; j<=1 ; j++){
        //         for(int k=0; k<=2; k++){
        //             int op1 = dp[i+1][j][k];
        //             if(j) dp[i][j][k] = max(-prices[i] + dp[i+1][j-1][k], op1);
        //             else dp[i][j][k] = max(prices[i] + dp[i+1][j+1][k+1], op1);
        //         }
        //     }
        // }
        // return dp[0][1][1];

        vector<vector<int>> dp(2, vector<int> (4, 0));
        for(int i= n-1; i>=0; i--){
            vector<vector<int>> curr(2, vector<int> (4, 0));
            for(int j = 0; j<=1 ; j++){
                for(int k=0; k<=2; k++){
                    int op1 = dp[j][k];
                    if(j) curr[j][k] = max(-prices[i] + dp[j-1][k], op1);
                    else curr[j][k] = max(prices[i] + dp[j+1][k+1], op1);
                }
            }
            dp = curr;
        }
        return dp[1][1];
    }
};