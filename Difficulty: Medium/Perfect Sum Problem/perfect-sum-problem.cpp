//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int ind, int target,int n, vector<int>& arr, vector<vector<int>> &dp){
        if(target == 0){
            return 1;
        }
        if(ind >= n ){
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int pick = arr[ind] <= target ? fun(ind+1 ,target - arr[ind],  n, arr, dp) : 0;
        int skip = fun(ind+1, target, n, arr, dp);
        return dp[ind][target] = pick + skip;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(arr[i] == 0) cnt++;
            else break;
        }
        
        // MEMOIZATION
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return (pow(2,cnt))*fun(cnt, target, n, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends