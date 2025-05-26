class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> a, b;

        int cnt = 0;
        for(int i=0; i<t.length(); i++){
            a[t[i]]++;
        }
        cnt = a.size();
        int i=0;
        int start = i, end = -1;
        int minStart = 0, minEnd = INT_MAX-1;

        for(int j=0; j<n; j++){
            b[s[j]]++;
            if(a.find(s[j]) != a.end() && a[s[j]] == b[s[j]]){
                cnt--;
            }
            while(cnt == 0){
                start = i;
                end = j;
                
                if(end - start < minEnd-minStart){
                    minStart = start;
                    minEnd = end;
                }
                // cout<<minStart<<"," << minEnd << endl;
                b[s[i]]--;
                if(a.find(s[i]) != a.end() && b[s[i]] < a[s[i]]) cnt++;
                i++;
            }
        }
        // cout<<minStart<<"," << minEnd << endl;
        return minEnd - minStart + 1 >= t.length() && minEnd-minStart + 1 <= n ? s.substr( minStart, minEnd-minStart+1) : "";
    }
};