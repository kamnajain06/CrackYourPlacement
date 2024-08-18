class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            int ones = 0;
            int xeroes = 0;
            for(int j=i; j<s.length(); j++){
                if(s[j] == '1') ones++;
                else if(s[j] == '0') xeroes++;
                
                if(ones <= k || xeroes <= k) ans++;
            }
        }
        return ans;
    }
};