class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i=0; i<n; i++){
            long long lowerBoundElement = lower - nums[i];
            long long upperBoundElement = upper - nums[i];

            int lowerBound = lower_bound(nums.begin()+i+1, nums.end(), lowerBoundElement) - nums.begin();
            int upperBound = upper_bound(nums.begin()+i+1, nums.end(), upperBoundElement) - nums.begin();

            // cout<<lowerBound<<" , "<<upperBound<<endl;

            cnt += (upperBound - lowerBound);
        }
        return cnt;
    }
};