class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // T.c = o(n^2) , s.c = O(n)
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(i >= 1 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n; j++){
                if(j-1>i && nums[j] == nums[j-1]) continue;
                int val = -(nums[i]+nums[j]);
                if(mpp.find(val) != mpp.end() && mpp[val] > i && mpp[val] > j){
                    ans.push_back({nums[i], nums[j], val});
                }
            }
            
        }
        return ans;
    }
};