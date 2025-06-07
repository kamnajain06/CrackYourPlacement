class Solution {
public:
    // int f(int i, int prev, int n, vector<int> &nums, vector<vector<int>> &dp){
    //     if(i >= n) return 0;
    //     if(dp[i][prev+1] != -1) return dp[i][prev+1];
    //     int take = 0;
    //     int skip = f(i+1, prev, n, nums, dp);
    //     if(prev == -1 || nums[i] > nums[prev]){
    //         take = 1 + f(i+1, i, n, nums, dp);
    //     }

    //     return dp[i][prev+1] = max(take, skip);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return f(0, -1, n, nums, dp);

        // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        // for(int i=n-1; i>=0; i--){
        //     for(int j = i-1; j >= -1; j--){
        //         int skip = dp[i+1][j+1];
        //         int take = 0;
        //         if(j == -1 || nums[i] > nums[j]){
        //             take = 1 + dp[i+1][i+1];
        //         }
        //         dp[i][j+1] = max(take, skip);
        //     }
        // }
        // return dp[0][0];

        // vector<int> dp(n+1, 0);
        // for(int i=n-1; i>=0; i--){
        //     vector<int> curr(n+1, 0);
        //     for(int j = i-1; j >= -1; j--){
        //         int skip = dp[j+1];
        //         int take = 0;
        //         if(j == -1 || nums[i] > nums[j]){
        //             take = 1 + dp[i+1];
        //         }
        //         curr[j+1] = max(take, skip);
        //     }
        //     dp = curr;
        // }
        // return dp[0];

        // vector<int> dp(n+1, 1);
        // int maxi = 1;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<i; j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(1+dp[j], dp[i]);
        //         }
        //         maxi = max(maxi, dp[i]);
        //     }
        // }
        // return maxi;

        // Binary Search
        vector<int> bs;
        for(int i=0; i<n; i++){
            auto it = lower_bound(bs.begin(), bs.end(), nums[i]);
            if(it == bs.end()){
                bs.push_back(nums[i]);
            }else{
                int ind = it - bs.begin();
                bs[ind] = nums[i];
            }
        }
        return bs.size();

    }
};