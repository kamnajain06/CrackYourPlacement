class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int prefix_sum = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            prefix_sum += nums[i];
            ans += mpp[prefix_sum-goal];
            mpp[prefix_sum]++;
        }
        return ans;
    }
};