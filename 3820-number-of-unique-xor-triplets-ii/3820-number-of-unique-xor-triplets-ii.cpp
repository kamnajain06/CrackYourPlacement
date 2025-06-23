class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairs;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pairs.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> ans;
        for(auto &it:pairs){
            for(int i=0; i<n; i++){
                ans.insert(it^nums[i]);
            }
        }
        return ans.size();
    }
};