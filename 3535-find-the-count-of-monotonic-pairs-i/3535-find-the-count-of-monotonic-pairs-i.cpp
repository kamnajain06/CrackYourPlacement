#include <cmath>
class Solution {
public:
    int dp[2001][51];

    long long function(vector<int>& nums, long long ind, long long pv1) {
        int n = nums.size();

        if (ind == n) return 1;

        if (dp[ind][pv1] != -1) return dp[ind][pv1];

        int pv2 = (ind > 0) ? nums[ind - 1] - pv1 : INT_MAX;

        long long ans = 0;

        for (int i = pv1; i <= nums[ind]; i++) {
            int i2 = nums[ind] - i;

            if (i2 > pv2) continue;

            ans = (ans + function(nums, ind + 1, i)) % 1000000007;
        }

        return dp[ind][pv1] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return function(nums, 0, 0)%(1000000007);
    }
};