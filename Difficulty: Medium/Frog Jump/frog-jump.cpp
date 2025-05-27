class Solution {
  public:
    // int f(int i, vector<int> &height, int n, vector<int> &dp){
    //     if(i >= n) return 1e7;
    //     if(dp[i] != -1) return dp[i];
    //     if(i == n-1) return 0;
    //     int step1 = abs(height[i+1] - height[i]) +  f(i+1, height , n, dp);
    //     int step2 = abs(height[i+2] - height[i]) + f(i+2, height, n, dp);
        
    //     return dp[i] = min(step1, step2);
    // }
    int minCost(vector<int>& height) {
        int n = height.size();
        // vector<int> dp(n, -1);
        // return f(0, height, n, dp);
        
        // vector<int> dp(n+1, 0);
        // for(int i = n-2; i>=0; i--){
        //     int step1 = abs(height[i+1] - height[i]) +  dp[i+1];
        //     int step2 = i + 2 < n ? abs(height[i+2] - height[i]) + dp[i+2] :1e7;
            
        //     dp[i] = min(step1, step2);
        // }
        
        // return dp[0];
        
        int prev1 = 0, prev2 = 0;
        for(int i = n-2; i>=0; i--){
            int step1 = abs(height[i+1] - height[i]) +  prev1;
            int step2 = i + 2 < n ? abs(height[i+2] - height[i]) + prev2 :1e7;
            
            int curr = min(step1, step2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};