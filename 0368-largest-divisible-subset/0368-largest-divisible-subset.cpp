class Solution {
public:
    // int fun(int i, vector<int> &nums, int n, int prev){
    //     if(i == n) return 0;

    //     if(nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0){
    //         return max(1 + fun(i+1, nums, n, i), fun(i+1, nums, n, prev));
    //     }
    //     return fun(i+1, nums, n, i);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // int val = fun(1, nums, n, 0) + 1;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> backtrack(n);
        for(int i=0; i<n; i++) backtrack[i] = i;
        int maxLen = 1;
        int ind = 0;
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    backtrack[i] = prev;
                }
            }
            maxLen = max(maxLen, dp[i]); 
            if(dp[i] > dp[ind]) ind = i;
        }
        
        vector<int> ans(maxLen);
        ans[0] = nums[ind]; 
        int i = 1;
        while(backtrack[ind] != ind){
            ans[i] = nums[backtrack[ind]];
            ind = backtrack[ind];
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};