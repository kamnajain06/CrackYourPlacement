class Solution {
public:
    void backtrack(int index ,vector<int>& nums,vector<int> &ele, vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(ele);
            return;
        }
        ele.push_back(nums[index]);
        backtrack(index+1,nums, ele, ans);
        ele.pop_back();

        backtrack(index+1,nums, ele, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ele;
        backtrack(0 ,nums , ele, ans);
        return ans;
    }
};