class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mpp; 
        int cnt = 1;
        int prev = nums[0]-k;
        for(int i=1; i<nums.size(); i++){
            int lb = nums[i]-k;
            int ub = nums[i]+k;
            if(prev + 1 >= lb && prev + 1 <= ub){
                prev++;
                cnt++;
            }
            else if(lb > prev+1){
                prev = lb;
                cnt++;
            }
        }
        return cnt;
    }
};