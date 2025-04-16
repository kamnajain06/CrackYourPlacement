class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0, r = 1;
        mpp[nums[0]]++;

        int cnt = 0;
        long long ans = 0;
        while (r < n) {
            if(mpp.find(nums[r]) != mpp.end()) cnt += mpp[nums[r]];
            mpp[nums[r]]++;
            while(cnt >= k) {
                ans += (n - r);
                mpp[nums[l]]--;
                cnt -= (mpp[nums[l]]);
                l++;
            }
            r++;
        }
        return ans;
    }
};