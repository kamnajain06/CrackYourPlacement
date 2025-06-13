class Solution {
public:
    bool isPalindrome(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return s == temp;
    }
    void f(int i, int prev, int n, string &s, vector<string> &temp,  vector<vector<string>> &ans){
        if(i > n){
            if(prev >= n) ans.push_back(temp);
            return;
        }
        string st = s.substr(prev, i-prev);
        if(isPalindrome(st)){
            temp.push_back(st);
            f(i+1, i, n, s, temp, ans);
            temp.pop_back();
        }
        f(i+1, prev, n, s, temp, ans);
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> temp;
        f(1, 0, n, s, temp, ans);
        return ans;
    }
};