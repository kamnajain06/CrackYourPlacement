class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int k = n-1;
            int j = i+1;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(nums[j] + nums[k]  + nums[i] > 0){
                    k--;
                }else j++;
                while(j < n && j-1 > i && nums[j] == nums[j-1]) j++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};