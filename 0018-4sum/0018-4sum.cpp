class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                while (j < n && j - 1 > i && nums[j] == nums[j - 1]) j++;
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    if ((long long) nums[i] + nums[j] + nums[left] + nums[right] ==
                        target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    } else if ((long long) nums[i] + nums[j] + nums[left] + nums[right] >
                               target) {
                        right--;
                    } else
                        left++;
                }
            }
        }
        return ans;
    }
};