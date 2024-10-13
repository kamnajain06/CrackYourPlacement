class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int ans = 0;
        if(s.length() <= 1) return s.length();
        int j = 0;
        unordered_map<int,int> mpp;
        while(j < s.length() && i <= j ){
            if(mpp[(int)s[j]] == 0){
                mpp[(int)s[j]] = 1;
                ans = max(ans, j-i+1);
                j++;
            }else{
                mpp[(int)s[i]] = 0;
                i++;
            }
        }
        return ans;
    }
};