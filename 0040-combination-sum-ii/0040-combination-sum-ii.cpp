class Solution {
public:
    void backtrack(int index, vector<int> v, int sum , vector<int>& candidates, int target, vector<vector<int>> &ans ){
        if(sum == target){
            ans.push_back(v);
            return;
        }else if(sum > target || index >= candidates.size()) return;

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; 

            v.push_back(candidates[i]);
            backtrack(i + 1, v, sum + candidates[i], candidates, target, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(0, v, 0, candidates,target, ans);
        return ans;
    }
};