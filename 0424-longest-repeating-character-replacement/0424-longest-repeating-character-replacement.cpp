class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        int maxLen = 0;
        int i=0 , j=0;
        unordered_map<char,int> mpp;

        while(j < s.length() && i <= j){
            mpp[s[j]]++;
            maxfreq = max(maxfreq, mpp[s[j]]);
            while((j-i+1) - maxfreq > k){
                mpp[s[i]]--;
                maxfreq = 0;
                for(auto it:mpp){
                    maxfreq = max(maxfreq, it.second);
                }
                i++;
            }
            if((j-i+1)-maxfreq <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
            }
        }
        return maxLen;
    }
};