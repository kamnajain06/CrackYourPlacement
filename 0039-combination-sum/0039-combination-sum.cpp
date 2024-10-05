class Solution {
public:

    void backtrack(int index, int sum, vector<int> v, vector<int>& candidates, int target, vector<vector<int>> &ans){
        if(sum == target){
            ans.push_back(v);
            return;
        }else if(sum > target  || index >= candidates.size()){
            return;
        }
        v.push_back(candidates[index]);
        backtrack(index, sum+candidates[index], v, candidates, target, ans);
        v.pop_back();

        backtrack(index+1, sum, v, candidates, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> v;
        backtrack(0, sum, v, candidates, target, ans );
        return ans;
    }
};