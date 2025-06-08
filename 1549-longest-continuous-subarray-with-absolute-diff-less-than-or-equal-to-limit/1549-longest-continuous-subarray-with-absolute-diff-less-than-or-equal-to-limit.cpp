class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int l = 0, len = 1;
        for(int r=0; r<n; r++){
            st.insert(nums[r]);
            int maxi = *prev(st.end());
            int mini = *st.begin();
            while(maxi-mini > limit){
                auto it = st.find(nums[l]);
                st.erase(it);
                l++;
                maxi = *prev(st.end());
                mini = *st.begin();
            }
            len = max(len, r-l+1);
        }
        return len;
    }
};