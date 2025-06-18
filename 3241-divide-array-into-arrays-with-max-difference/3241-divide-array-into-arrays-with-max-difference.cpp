class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            vector<int> temp;
            if(i + 2 < n && nums[i+2] - nums[i] <= k){
                for(int k = i; k < i+3; k++){
                    temp.push_back(nums[k]);
                }
                ans.push_back(temp);
                i+=3;
            }else{
                vector<vector<int>> emptyAns;
                return emptyAns;
            }
        }
        return ans;
    }
};