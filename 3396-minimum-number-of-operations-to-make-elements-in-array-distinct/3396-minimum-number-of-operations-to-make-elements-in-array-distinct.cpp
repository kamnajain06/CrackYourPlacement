class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        int totalDupes = 0;
        for (auto it : mpp) {
            totalDupes += (it.second - 1);
        }
        int ans = 0;
        while (totalDupes > 0) {
            for (int i = 0; i < nums.size() && i < 3; i++) {
                if (mpp[nums[i]] > 1)
                    totalDupes--;
                mpp[nums[i]]--;
            }
            if (nums.size() < 3)
                nums.clear();
            else {
                nums = vector<int>(nums.begin() + 3, nums.end());
            }
            ans++;
        }
        return ans;
    }
};