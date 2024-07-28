class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mpp;
        int preSum = 0;
        int cnt = 0;
        mpp[0]=1;
        for(int i=0; i<nums.size(); i++){
            preSum = (preSum+(nums[i]%k)+k)%k;
            cnt+=mpp[preSum];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};