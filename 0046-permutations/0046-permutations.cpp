class Solution {
public:
    void rec(vector<int> &nums, int n, int idx, vector<vector<int>> &ans, vector<int> temp, vector<int> &used){
        for(int i=0; i<n; i++){
            if(!used[i]){
                temp.push_back(nums[i]);
                used[i] = 1;
                if(temp.size() == n){
                    ans.push_back(temp);
                }
                rec(nums, n, i, ans, temp, used);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<int> used(n, 0);
        rec(nums, n, -1, ans, temp, used);
        return ans;
    }
};