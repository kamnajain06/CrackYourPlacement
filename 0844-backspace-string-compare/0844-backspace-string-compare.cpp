class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        int i=0;
        while( i < s.length()){
            if(!st1.empty() && s[i] == '#') st1.pop();
            else if(s[i] != '#') st1.push(s[i]);
            i++;
        }
        i=0;
        while( i < t.length()){
            if(!st2.empty() && t[i] == '#') st2.pop();
            else if(t[i] != '#') st2.push(t[i]);
            i++;
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() == st2.top()){
                st1.pop();
                st2.pop();
            }else{
                return false;
            }
        }
        if(!st1.empty() || !st2.empty() ) return false;
        
        return true;
    }
};