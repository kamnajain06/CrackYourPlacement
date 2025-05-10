class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // 1. find the largest k such that a[k] < a[k+1]
        int k = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        int ind = -1;
        for(int i=k+1; i<n; i++){
            if(nums[i] > nums[k]){
                ind = i;
            }
        }
        swap(nums[ind], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};