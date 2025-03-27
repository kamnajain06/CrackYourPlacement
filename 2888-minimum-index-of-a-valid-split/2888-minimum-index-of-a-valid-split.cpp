class Solution {
public:
    int boyreMooreVoting(vector<int> &nums, int n){
        int cnt = 1;
        int candidate = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] != candidate){
                cnt--;
                if(cnt <= 0){
                    candidate = nums[i];
                    cnt = 1;
                }
            }else cnt++;
        }
        return candidate;
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // finding dominant element in the nums array
        int majorityElement = boyreMooreVoting(nums, n);
        int totalOcc = 0;
        for(auto it:nums){
            if(it == majorityElement) totalOcc++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == majorityElement){
                cnt++;
            }
            if((cnt > ((i+1)/2)) && (totalOcc - cnt > (n-i-1)/2)) return i;
        }
        return -1;
    }
};