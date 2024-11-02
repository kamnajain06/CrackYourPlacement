class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        string s = sentence;
        if(s[0] != s[n-1]) return false;
        for(int i=1; i<n; i++){
            if(i < n - 1 && s[i+1] == ' '){
                if(i+2 < n && s[i] == s[i+2]) continue;
                else return false;
            }
        }
        return true;
    }
};