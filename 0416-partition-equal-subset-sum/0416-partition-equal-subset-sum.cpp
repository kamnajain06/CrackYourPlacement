class Solution {
public:
    // bool fun(int i, int n, vector<int>& nums, int target,
    //          vector<vector<int>>& dp) {
    //     if (i >= n) {
    //         return target == 0;
    //     }
    //     if (dp[i][target] != -1)
    //         return dp[i][target];
    //     bool pick = nums[i] <= target
    //                     ? fun(i + 1, n, nums, target - nums[i], dp)
    //                     : false;
    //     bool skip = fun(i + 1, n, nums, target, dp);

    //     return dp[i][target] = pick | skip;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;

        // vector<vector<int>> dp(n , vector<int> (target+1, -1));
        // return fun(0, n, nums, target, dp);

        // vector<vector<int>> dp(n, vector<int>(target + 1, false));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(nums[i] <= target) dp[i][target] = true;
        // for (int i = n-1; i >= 0; i--) {
        //     for (int j = target; j >= 0; j--) {
        //         bool pick = nums[i] <= j
        //                         ? dp[i + 1][j - nums[i]]
        //                         : false;
        //         bool skip = dp[i + 1][j];

        //         dp[i][j] = pick | skip;
        //     }
        // }

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        if(nums[0] <= target) dp[nums[0]] = true;

        for(int i=1; i<n; i++){
            vector<bool> temp(target+1, false);
            temp[0] = true;
            for (int j = 0; j <= target; j++) {
                bool pick = nums[i] <= j
                                ? dp[j - nums[i]]
                                : false;
                bool skip = dp[j];

                temp[j] = pick | skip;
            }
            dp = temp;
        }
        return dp[target];
    }
};