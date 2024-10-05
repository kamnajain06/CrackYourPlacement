class Solution {
public:
    void backtrack(int indx, string digits, string v, vector<string> &ans,unordered_map<char,string> &mpp ){
        if(indx >= digits.length() ){
            ans.push_back(v);
        }
        string mapped = mpp[digits[indx]];
        for(int i = 0; i<mapped.length(); i++){
            backtrack(indx+1, digits, v + mapped[i], ans, mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> mpp;
        if(digits.length() == 0) return ans;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        backtrack(0,digits,"",ans,mpp);
        return ans;
    }
};