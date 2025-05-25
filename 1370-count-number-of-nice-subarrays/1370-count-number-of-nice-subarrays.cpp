class Solution {
public:
    int cntAtLeast(vector<int> &nums, int n, int k){
        int cnt = 0, ans = 0;
        int i = 0;
        for(int j = 0; j<n; j++){
            cnt += (nums[j] % 2 == 1);
            while(cnt >= k){
                ans += n-j;
                cnt -= (nums[i++] % 2 == 1);
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return cntAtLeast(nums, n, k) - cntAtLeast(nums, n, k+1);
    }
};