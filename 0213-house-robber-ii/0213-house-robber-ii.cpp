class Solution {
public:
    int fun(int n, int sum, vector<int> &nums, vector<int> &dp){
        if(n >= nums.size()){
            return 0;
        }
        if(dp[n] != -1) return dp[n];
        int left = fun(n+2, sum , nums, dp);
        int right = fun(n+1, sum, nums, dp);
        return dp[n] = max(nums[n] + left, right);
    }
    int fun1(int n, int sum, vector<int> &nums, vector<int> &dp1){
        if(n >= nums.size()-1){
            return 0;
        }
        if(dp1[n] != -1) return dp1[n];
        int left = fun1(n+2, sum , nums, dp1);
        int right = fun1(n+1, sum, nums, dp1);
        return dp1[n] = max(nums[n] + left, right);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        vector<int> dp1(nums.size(), -1);
        if(nums.size() == 1) return nums[0];
        return max(fun(1, 0, nums, dp), fun1(0,0,nums,dp1));
    }
};