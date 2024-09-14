class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        int ans = 0;
        for(auto it:nums){
            maxi = max(maxi, it);
        }
        for(auto it:nums){
            if(it == maxi) cnt++;
            else cnt = 0;
            ans = max(ans,cnt);
        }
        return ans;
    }
};