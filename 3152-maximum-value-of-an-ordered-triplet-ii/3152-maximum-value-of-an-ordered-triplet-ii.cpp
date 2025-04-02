class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left (n, 0), right(n , 0);
        left[0] = nums[0];
        left[1] = nums[0];
        for(int i=2; i<n; i++){
            left[i] = max(nums[i-1], left[i-1]);
        }
        right[n-1] = nums[n-1];
        right[n-2] = nums[n-1];
        for(int i=n-3; i>=0; i--){
            right[i] = max(nums[i+1], right[i+1]);
        }
        long long maxi = 0;
        for(int i=1; i<n-1; i++){
            long long temp = (left[i] - nums[i]);
            if(temp >= 0){
                maxi = max(maxi, temp*right[i]);
            }
        }
        return maxi;
    }
};