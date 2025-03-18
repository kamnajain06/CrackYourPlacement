class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 1;
        int n = nums.size();
        int ans = 1;
        long long prefix_sum  = nums[left];
        while(right < n){
            if((prefix_sum + nums[right]) == (prefix_sum ^ nums[right])){
                    prefix_sum += nums[right];
                    ans = max(ans, right - left + 1);
                    right++;
                }else{
                   prefix_sum -= nums[left];
                   left++;
                }
            
        }
        // ans = max(ans, right-left);
        return ans;
    }
};