class Solution {
public:
    void rec(int n , vector<int> &nums, vector<int> &used, vector<int> &temp, set<vector<int>> &st){
        for(int i=0; i<n; i++){
            if(!used[i]){
                temp.push_back(nums[i]);
                used[i] = 1;
                if(temp.size() == n) st.insert(temp);
                rec(n, nums, used, temp, st);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<int> temp, used(n,0);
        rec(n, nums, used, temp, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};