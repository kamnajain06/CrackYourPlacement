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
        vector<int> dp(nums.size()+1, -1);
        int cnt = fun(0, 0, nums, dp);
        return cnt;
    }
};