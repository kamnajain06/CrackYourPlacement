class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mpp;
        int flag = 0;
        for(auto it: nums){
            if(it >= 0){
                flag = 1;
                if(mpp.find(it) == mpp.end()){
                    mpp[it]++;
                    sum += it;
                }
            }
        }
        if(!flag) return *max_element(nums.begin(), nums.end());
        return sum;
    }
};