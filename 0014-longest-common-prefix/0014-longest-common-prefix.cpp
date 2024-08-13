class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans="";
        int n= strs.size();
        int i=0;
        if(strs[0] == "") return "";
        if(strs.size() == 1) return strs[0];
        while(n>1 && i<strs[0].size() && strs[0][i] == strs[n-1][i]){
            ans+=strs[0][i];
            i++;
        }
        return ans;
    }
};