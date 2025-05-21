class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int val = 1;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            val *= nums[j];

            while(i < j && val >= k) val = val/nums[i++];

            if(nums[j] < k) cnt++;
            cnt += (j-i);

        }
        return cnt;
    }
};