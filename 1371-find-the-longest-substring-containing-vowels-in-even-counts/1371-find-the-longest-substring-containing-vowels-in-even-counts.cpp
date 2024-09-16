class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> mpp;
        int mask = 0;

        mpp[0] = -1;
        int len = 0;
        int maxi = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                mask ^= s[i];
            }else{
                mask ^= 0;
            }
            if(mpp.find(mask) == mpp.end()){
                mpp[mask] = i;
            }else{
                len = i - mpp[mask];
            }

            maxi = max(maxi,len);
        }
        return maxi;
    }
};