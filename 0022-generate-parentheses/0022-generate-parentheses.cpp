class Solution {
public:
    vector<string> ans;
    bool check(string s, int n){
        stack<char> st;
        if(s[0] == ')') return false;
        for(int i=0; i<s.length(); i++){
            if(st.empty() && s[i] == ')')  return false;
            else if(s[i] == '(') {
                st.push('(');
            }
            else st.pop();
        }
        if(st.empty()) return true;
        return false;
    }

    void generateStrings(string s, int countOpen, int countClose, vector<string> &ans, int n){
        if(countClose > countOpen || countOpen > n) return;
        if(check(s,n) && countOpen == n) ans.push_back(s);

        generateStrings(s+"(", countOpen+1, countClose, ans, n);
        generateStrings(s+")",countOpen, countClose+1, ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateStrings("(", 1, 0, ans, n);
        return ans;
    }
};