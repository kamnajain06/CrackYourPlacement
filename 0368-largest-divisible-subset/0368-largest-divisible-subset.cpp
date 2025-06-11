class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), backtrack(n, 0);
        iota(backtrack.begin(), backtrack.end(), 0);
        int maxInd = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        backtrack[i] = j;
                        if(dp[i] > dp[maxInd]) maxInd = i;
                    }
                }
            }
        }
        int ind = maxInd;
        vector<int> v;
        while(backtrack[ind] != ind){
            v.push_back(nums[ind]);
            ind = backtrack[ind];
        }
        v.push_back(nums[ind]);
        reverse(v.begin(), v.end());
        return v;

    }
};