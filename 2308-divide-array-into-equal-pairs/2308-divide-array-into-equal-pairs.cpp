class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int cnt = 0;
        for(auto it:mpp){
            if(it.second%2 == 0){
                cnt += (it.second/2);
            }else return false;
        }
        return cnt == n/2;
    }
};