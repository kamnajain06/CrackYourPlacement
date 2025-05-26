class Solution {
public:
    // int f(int i, vector<int> &nums, int n, vector<int> &dp){
    //     if(i >= n) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int take = nums[i] + f(i+2, nums, n, dp);
    //     int skip = f(i+1, nums, n, dp);

    //     return dp[i] = max(take, skip);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return f(0, nums, n, dp);

        // vector<int> dp(n, 0);
        int prev1 = 0, prev2 = 0;
        for(int i=n-1; i>=0; i--){
            int take = i + 2 < n ? nums[i] + prev2 : nums[i];
            int skip = i + 1 < n ? prev1 : 0;

            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};