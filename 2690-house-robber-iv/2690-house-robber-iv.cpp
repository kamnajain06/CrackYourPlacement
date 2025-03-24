class Solution {
public:
    bool isPossible(vector<int> &nums, int k, int val){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= val){
                i++;
                k--;
            }
        }
        return k <= 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int mini = 0, maxi = 0;
        for(auto it:nums){
            mini = min(it, mini);
            maxi = max(it, maxi);
        }
        int left = mini, right = maxi;
        while(left < right){
            int mid = left + (right - left)/2;
            if(isPossible(nums, k, mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};