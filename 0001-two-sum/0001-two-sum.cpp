class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans(2,-1);
        
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target-nums[i]) != mpp.end()){
                    ans[0] = mpp[target-nums[i]];
                    ans[1] = i;
                 break;
               
            }else{   
                mpp[nums[i]] = i;
            }
        }
        
        return ans;
    }
};