class Solution {
public:
    // bool f(int i, int n, int target, vector<int> &nums){
    //     if(i >= n ) return target == 0;
    //     if(target == 0) return true;
    //     if(target < 0) return false;

    //     return f(i+1, n, target - nums[i], nums) || f(i+1, n, target, nums);
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 == 1) return false;

        // return f(0, n, sum/2, nums);
        vector<int> dp((sum/2) + 1, false);
        dp[0] = true;
        if(nums[0] <= (sum/2)) dp[nums[0]] = true;
        
        for(int i = 1; i<n; i++){
            vector<int> curr((sum/2) + 1, false);
            curr[0] = true;
            for(int j = 1; j<= sum/2; j++){
                curr[j] = (j - nums[i] >= 0 ? dp[j-nums[i]] : false) || dp[j];
            }
            dp = curr;
        }


        return dp[sum/2];
    }
};