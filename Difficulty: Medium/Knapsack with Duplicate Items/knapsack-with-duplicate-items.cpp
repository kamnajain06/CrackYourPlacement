//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int fun(int ind, int capacity , vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){
    //     if(capacity == 0) return 0;
    //     if(ind >= n) return 0;
        
    //     if(dp[ind][capacity] != -1) return dp[ind][capacity];
        
    //     int pick = capacity >= wt[ind] ? val[ind] + fun(ind, capacity - wt[ind], val, wt, n, dp) : 0;
    //     int skip = fun(ind+1, capacity, val, wt, n, dp);
        
    //     return dp[ind][capacity] = max(pick, skip);
    // }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n = val.size();
    //   vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
    // //   MEMOIZATION
    //   return fun(0, capacity, val, wt, n, dp);
    
        // // TABULATION
        // vector<vector<int>> dp(n, vector<int> (capacity+1, 0));
        // if(wt[0] <= capacity){
        //     for(int cap = wt[0]; cap <= capacity; cap++){
        //         dp[0][cap] = val[0];
        //     }
        // }
        
        // for(int row=0; row<n; row++){
        //     for(int sum=1; sum<= capacity; sum++){
        //         int pick = sum >= wt[row] ? val[row] + dp[row][sum - wt[row]] : 0;
        //         int skip = (row > 0) ? dp[row-1][sum] : 0;
        //         dp[row][sum] = max(pick, skip);
        //     }
        // }
        // return dp[n-1][capacity];
        
        // SPACE OPT
        vector<int> dp(capacity+1, 0);
        if(wt[0] <= capacity){
            for(int cap = wt[0]; cap <= capacity; cap++){
                dp[cap] = val[0];
            }
        }
        
        for(int row=0; row<n; row++){
            vector<int> temp(capacity+1, 0);
            for(int sum=1; sum<= capacity; sum++){
                int pick = sum >= wt[row] ? val[row] + temp[sum - wt[row]] : 0;
                int skip = (row > 0) ? dp[sum] : 0;
                temp[sum] = max(pick, skip);
            }
            dp = temp;
        }
        return dp[capacity];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends