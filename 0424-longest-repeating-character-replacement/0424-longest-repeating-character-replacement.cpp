class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int i = 0;
        int len = 1;

        vector<int> v(26, 0);
        int j=0;
        for(; j<n; j++){
            v[s[j]-'A']++;
            while((j-i+1)-*max_element(v.begin(),v.end()) > k){
                v[s[i]-'A']--;
                i++;
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};