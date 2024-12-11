//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // bool fun(int ind, int target,int n, vector<int>& arr, vector<vector<int>> &dp){
    //     if(target == 0){
    //         return true;
    //     }
    //     if(ind >= n ){
    //         return false;
    //     }
    //     if(dp[ind][sum] != -1) return dp[ind][sum];
        
    //     int pick = arr[ind] <= target ? fun(ind+1 ,target - arr[ind],  n, arr, dp) : false;
    //     int skip = fun(ind+1, target, n, arr, dp);
    //     return dp[ind][sum] = pick || skip;
    // }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        // MEMOIZATION
        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // return fun(0, 0, target, n, arr, dp);
        
        // // TABULATION
        // vector<vector<int>> dp(n, vector<int> (target+1, 0));
        
        // SPACE OPTIMIZATION
        vector<int> dp(target+1, 0);
        
        dp[0] = true;
        if(arr[0] <= target) dp[arr[0]] = true;
        
        for(int i=1; i<n; i++){
            vector<int> temp(target+1, 0);
            temp[0] = true;
            for(int j=1; j<=target; j++){
                int pick = arr[i] <= j && i-1 >=0 ? dp[j - arr[i]] : false;
                int skip = i-1 >= 0 ? dp[j]: false;
                temp[j] = pick || skip;
            }
            dp = temp;
        }
        return dp[target];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends