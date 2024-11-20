class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int cnt = 0;
        int maxCount = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i] == ' '){
                cnt = 0;
            }else cnt++;
            if(cnt > 0 ){
                if(!st.empty()){
                    st.pop();  
                }
                st.push(cnt);
            }
        }
        return st.top();
    }
};