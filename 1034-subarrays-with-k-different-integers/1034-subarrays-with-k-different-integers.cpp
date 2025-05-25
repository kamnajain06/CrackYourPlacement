class Solution {
public:
    int cntAtleast(vector<int>& nums, int k){
        int i = 0;
        unordered_map<int,int> mpp;
        int cnt = 0;
        for(int j=0; j<nums.size(); j++){
            mpp[nums[j]]++;
            while(mpp.size() >= k){
                cnt += nums.size()-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exactly k = atleast k - atleast k + 1;

        return cntAtleast(nums, k) - cntAtleast(nums, k+1);
    }
};