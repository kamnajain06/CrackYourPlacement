//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int prec(char ch){
        if(ch == '+' || ch == '-') return 1;
        else if(ch == '*' || ch == '/') return 2;
        return 3;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<int> st;
            
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
            }else{
                if(st.empty() || s[i] == '(') st.push(s[i]);
                else if(s[i] == ')'){
                    while(!st.empty() && st.top() != '('){
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                }else if(st.top() == '(') st.push(s[i]);
                else if(prec(s[i]) > prec(st.top())){
                    st.push(s[i]);
                }else if(prec(s[i]) <= prec(st.top())){
                    while(!st.empty() && prec(s[i]) <= prec(st.top())){
                        if(st.top() == '(') break;
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.
//   Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends