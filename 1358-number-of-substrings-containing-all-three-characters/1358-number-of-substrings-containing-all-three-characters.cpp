class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int i=0, j=0;
        unordered_map<char,int> mpp;

        while(j<s.length() && i <= j){
            mpp[s[j]]++;
            while(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                cnt += s.length()-j;
                mpp[s[i]]--;
                i++;
            }
                j++;
        }
        return cnt;
    }
};