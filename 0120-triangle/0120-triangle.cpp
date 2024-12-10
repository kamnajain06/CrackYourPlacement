class Solution {
public:
//     int fun(int i, int j,int n, vector<vector<int>>& triangle, vector<vector<int>> &dp){
//             if(j > i) return INT_MAX;
//             if(i == n-1) return triangle[i][j];

//             if(dp[i][j] != -1) return dp[i][j];

//             return dp[i][j] =  triangle[i][j] + min(fun(i+1, j, n ,triangle, dp), fun(i+1, j+1, n, triangle, dp));
//         }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector< vector<int> > dp(n, vector<int> (n, -1));
        // return fun(0, 0, n, triangle, dp);

//         Tabulation
//         vector< vector<int> > dp(n, vector<int> (n, 0));
//         for(int i=0; i<n ; i++){
//             for(int j=0; j<=i; j++){
//                 if(i == 0 && j == 0) dp[i][j] = triangle[i][j];
//                 else{
//                     int up = i - 1 >= j ? triangle[i][j] + dp[i-1][j] : INT_MAX;
//                     int left = i - 1 >= j - 1 && j - 1 >= 0 ? triangle[i][j] + dp[i-1][j-1] : INT_MAX;

//                     dp[i][j] = min(up, left);
//                 }
//             }
//         }
//         int ans = INT_MAX;
//         for(auto it:dp[n-1]){
//             ans = min(ans, it);
//         }
//         return ans;

//         SPACE OPTIMIZATION

        vector<int> dp(n, 0);
        // dvector< vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0; i<n ; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<=i; j++){
                if(i == 0 && j == 0) temp[j] = triangle[i][j];
                else{
                    int up = i - 1 >= j ? triangle[i][j] + dp[j] : INT_MAX;
                    int left = i - 1 >= j - 1 && j - 1 >= 0 ? triangle[i][j] + dp[j-1] : INT_MAX;
                    temp[j] = min(up, left);
                }
            }
            dp = temp;
        }
            
        int ans = INT_MAX;
        for(auto it: dp){
            ans = min(ans, it);
        }
        return ans;
    }
};