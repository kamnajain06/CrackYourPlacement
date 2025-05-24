class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int len = 0;
        int sum = 0;
        for(int j = 0; j<n; j++){
            sum += nums[j];
            while(sum < j-i) sum -= nums[i++];

            len = max(len, j-i);
        }
        return len;
    }
};