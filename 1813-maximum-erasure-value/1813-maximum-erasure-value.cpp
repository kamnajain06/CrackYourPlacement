class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0, maxSum = 0;
        unordered_map<int,int> freqMpp;
        for(int j = 0; j<n; j++){
            sum += nums[j];
            freqMpp[nums[j]]++;
            while(freqMpp[nums[j]] > 1){
                freqMpp[nums[i]]--;
                sum -= nums[i++];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};