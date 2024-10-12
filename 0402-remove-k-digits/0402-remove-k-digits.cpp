class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;
        if(k == num.length()) return "0"; 
        for(int i=0; i<num.length(); i++){
            while(k > 0 && !st.empty() && num[i] < st.top()){
                st.pop();
                k--;
                if(k == 0) break;
            }
            st.push(num[i]);
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(k > 0){

            string str = "";
            for(int i=0; i<ans.length()-k; i++){
                str += ans[i];
            }
            ans = str;
        }
        if(ans[0] != '0') return ans;
        int i;
        for(i=0; i<ans.length(); i++){
            if(ans[i] == '0') continue;
            else break;
        }
        cout<<i<<endl;
    
        string s = ans.substr(i, ans.length());

        return s.length() > 0 ? s : "0" ;
    }
};