class Solution {
public:
    int fun(int ind , int target ,vector<int>& nums, int n){
        if(ind == n){
            if(target == 0) return 1;
            else return 0;
        }

        return fun(ind+1, target - nums[ind], nums, n) + fun(ind+1, target + nums[ind], nums, n);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return fun(0, target, nums, n);
    }
};