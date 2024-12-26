class Solution {
public:
    int f(int i, vector<int> &nums, int n, vector<vector<int>> &dp, int prev){
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        if(prev == -1 || nums[i] > nums[prev]){
            return dp[i][prev+1] = max( 1 + f(i+1, nums, n, dp, i), f(i+1, nums, n, dp, prev));
        }
        return dp[i][prev+1] = f(i+1, nums, n, dp, prev);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return f(0, nums, n, dp, -1);
        vector<int> dp(n+1,0);
        vector<int> before(n+1,0);

        
        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev >=-1; prev--){
                if(prev == -1 || nums[i] > nums[prev]){
                    before[prev+1] = max( 1 + dp[i+1], dp[prev+1]);
                }else{
                    before[prev+1] = dp[prev+1];
                }
            }
            dp = before;
        }
        return before[0];
    }
};