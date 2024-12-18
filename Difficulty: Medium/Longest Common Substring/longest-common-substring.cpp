//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int> dp(len2+1, 0);
        
        int maxi = 0;
            
        for(int i=1; i<=len1; i++){
            vector<int> temp(len2+1, 0);
            for(int j=1; j<=len2; j++){
                if(s1[i-1] == s2[j-1]){
                    temp[j] = 1 + dp[j-1];
                    maxi = max(maxi, temp[j]);
                }
            }
            dp = temp;
        }
        return maxi;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends