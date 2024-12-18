//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        vector<vector<set<string>>> dp(len1+1, vector<set<string>> (len2+1));
        
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j].insert("");
                }
            }
        }
        
        for(int i=1; i<=len1; i++){ 
            for(int j=1; j<=len2; j++){ 
                if(s[i-1] == t[j-1]){
                    for (auto it : dp[i - 1][j - 1]) {
                        dp[i][j].insert(it + s[i - 1]);
                    }
                }else{
                    if (dp[i - 1][j].begin()->size() >= dp[i][j - 1].begin()->size()) {
                        dp[i][j].insert(dp[i - 1][j].begin(), dp[i - 1][j].end());
                    }
                    if (dp[i][j - 1].begin()->size() >= dp[i - 1][j].begin()->size()) {
                        dp[i][j].insert(dp[i][j - 1].begin(), dp[i][j - 1].end());
                    }
                }
            }
        }
       vector<string> result(dp[len1][len2].begin(), dp[len1][len2].end());
    
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends