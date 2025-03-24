class Solution {
public:
    int fun(int prev, int ind, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(ind == n-1){
            return max(nums[prev], nums[ind]);
        }else if(ind >= n){
            return nums[prev];
        }
        if(dp[prev][ind] != -1) return dp[prev][ind];

        int op1 = max(nums[prev], nums[ind]) + fun(ind+1, ind+2, nums, n, dp);
        int op2 = max(nums[ind], nums[ind+1]) + fun(prev, ind+2, nums, n, dp);
        int op3 = max(nums[prev], nums[ind+1]) + fun(ind, ind+2, nums, n, dp);

        return dp[prev][ind] = min({op1, op2, op3});
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(0, 1, nums, n, dp);
    }
};