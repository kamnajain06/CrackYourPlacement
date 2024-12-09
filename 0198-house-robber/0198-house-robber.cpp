class Solution {
public:
    int fun(int n, int sum, vector<int> &nums, vector<int> &dp){
        if(n >= nums.size()){
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n] + fun(n+2, sum , nums, dp), fun(n+1, sum, nums, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = i-2 >= 0 ? nums[i] + dp[i-2] : nums[i];
            dp[i] = max(pick, dp[i-1]);
        }
        return dp[n-1];
    }
};