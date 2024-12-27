//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);
        vector<int> backtrack(n);
        for(int i=0; i<n; i++){
            backtrack[i] = i;
        }
        
        int maxInd = 0;
        int maxiLen = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(arr[i] > arr[prev] && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    backtrack[i] = prev;
                }
            }
            maxiLen = max(maxiLen, dp[i]);
            if(dp[i] > dp[maxInd]) maxInd = i;
        }
        vector<int> ans(maxiLen);
        ans[0] = arr[maxInd];
        int i=1;
        int ind = maxInd;
        while(backtrack[ind] != ind){
            ans[i] = arr[backtrack[ind]];
            ind = backtrack[ind];
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends