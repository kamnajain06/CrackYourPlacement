class Solution {
public:
    void backtrack(int idx, vector<int> nums, int k, int n, vector<vector<int>> &ans, vector<int> v, int sum){
        if(sum == n && k == 0){
            ans.push_back(v);
            return;
        }else if(sum > n || k < 0 || idx >= nums.size()) return;

        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
        v.push_back(nums[idx]);
        backtrack(idx+1,nums,k-1, n, ans, v, sum+nums[idx]);
        v.pop_back();
         
        backtrack(idx+1,nums,k, n, ans, v, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(0,nums,k,n,ans,v,0);
        return ans;
    }
};