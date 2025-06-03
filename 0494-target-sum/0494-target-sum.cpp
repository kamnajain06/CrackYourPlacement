class Solution {
public:
    // int f(int i , int n, vector<int> &nums, int sum, int target){
    //     if(i >= n){
    //         if(sum == target){
    //             return 1;
    //         }
    //         return 0;
    //     }

    //     int add =  f(i+1, n, nums, sum-nums[i], target) ;
    //     int sub =  f(i+1, n, nums, sum+nums[i], target) ;

    //     return add + sub;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // return f(0, n, nums, 0, target); 

        // 2nd way improve it by s1-s2 = D;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int goal = (target + totalSum )/2;

        if((target + totalSum)%2 != 0 || target+totalSum < 0) return 0;

        vector<int> dp(goal + 1, 0);
        dp[0] = 1;
        if(nums[0] <= goal) dp[nums[0]] += 1;

        for(int i=1; i<n; i++){
            vector<int> curr(goal + 1, 0);
            for(int k = 0; k<= goal; k++){
                int take = k-nums[i] >= 0 ?dp[k-nums[i]] : 0;
                int skip = dp[k];
                
                curr[k] = take + skip;
            }
            dp = curr;
        }
        return dp[goal];

        
    }
};