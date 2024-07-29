class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
        int cnt=0;
        int preSum = 0;
        
        mpp[0] = 1;
        
        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];
            cnt += mpp[preSum-k];
            mpp[preSum]++;
        }
        
        return cnt;
    }
};