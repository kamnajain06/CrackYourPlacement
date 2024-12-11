class Solution {
public:
    // bool fun(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
    //     if(target == 0 && ind > 0) return true;
    //     if(ind < 0) return false;

    //     if(dp[ind][target] != -1) return dp[ind][target];

    //     int pick = nums[ind] <= target ? fun(ind-1, target-nums[ind], nums, dp) : false;
    //     int skip = fun(ind-1, target, nums, dp);
    //     return dp[ind][target] = pick | skip; 
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;

        int target = sum/2;

        // MEMOIZATION
        // vector<vector<int>> dp(n, vector<int> (target+1, -1));
        // return fun(n-1, target, nums, dp);

        // // TABULATION
        // vector<vector<int>> dp(n, vector<int> (target+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(nums[0] <= target){
        //     dp[0][nums[0]] = true;
        // }
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<=target; j++){
        //         int pick = nums[i] <= j ? dp[i-1][j-nums[i]]  : false;
        //         int skip = dp[i-1][j];
        //         dp[i][j] = pick | skip; 
        //     }
        // }
        // return dp[n-1][target];

        // SPACE OPT
        vector<int> dp(target+1, 0);
        dp[0] = true;

        if(nums[0] <= target){
            dp[nums[0]] = true;
        }

        for(int i=1; i<n; i++){
            vector<int> temp(target+1, 0);
            temp[0] = true;
            for(int j=0; j<=target; j++){
                int pick = nums[i] <= j ? dp[j-nums[i]]  : false;
                int skip = dp[j];
                temp[j] = pick | skip; 
            }
            dp = temp;
        }
        return dp[target];
    }
};