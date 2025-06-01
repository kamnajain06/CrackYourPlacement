class Solution {
public:
    // int f(int i, int j, int n, vector<vector<int>>& triangle){
    //     if(i == n-1){
    //         return triangle[i][j];
    //     }
    //     if(j > i) return 1e9;
    //     return triangle[i][j] + min(f(i+1, j, n, triangle), f(i+1, j+1, n, triangle));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return f(0, 0, n, triangle);

        // vector<vector<int>> dp(n, vector<int> (n, 1e9));
        // dp[n-1] = triangle[n-1];
        // for(int i=n-2; i>=0; i--){
        //     for(int j = i; j>=0; j--){
        //         dp[i][j] = triangle[i][j] + min(dp[i+1][j] , dp[i+1][j+1]);
        //     }
        // }
        // return dp[0][0];


        vector<int> dp(n, 1e9);
        dp = triangle[n-1];
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 1e9);
            for(int j = i; j>=0; j--){
                curr[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
            dp = curr;
        }
        return dp[0];

    }
};