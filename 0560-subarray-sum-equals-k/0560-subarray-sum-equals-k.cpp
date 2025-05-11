class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int prefix_sum = 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            prefix_sum += nums[i];
            cnt += mpp[prefix_sum - k];
            mpp[prefix_sum]++;
        }
        return cnt;
    }
};