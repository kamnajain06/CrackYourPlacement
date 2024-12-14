//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int fun(int ind, int capacity, vector<int> &price, int n, vector<vector<int>> &dp){
    //     if(capacity == 0) return 0;
    //     if(ind > n) return 0;
    //     if(dp[ind][capacity] != -1) return dp[ind][capacity];
    //     int pick = capacity >= ind ? price[ind-1] + fun(ind, capacity-ind, price, n, dp) : 0;
    //     int skip = fun(ind+1, capacity,  price, n, dp);
        
    //     return dp[ind][capacity] =  max(pick, skip);
    // }
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        // MEMOIZATION
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return fun(1, n, price, n, dp);
        
        // // TABULATION
        // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        // for(int col = 1; col <= n; col++){
        //     dp[0][col] = price[0];
        // }
        // for(int row = 1; row <= n; row++){
        //     for(int col = 1; col <= n ; col++){
        //         int pick = col >= row ? price[row-1] + dp[row][col-row] : 0;
        //         int skip = dp[row-1][col];
        //         dp[row][col] =  max(pick, skip);
        //     }
        // }
        // return dp[n][n];
        
        // SPACE OPT
        vector<int> dp(n+1, 0);
        for(int col = 1; col <= n; col++){
            dp[col] = price[0];
        }
        for(int row = 1; row <= n; row++){
            vector<int> temp(n+1, 0);
            for(int col = 1; col <= n ; col++){
                int pick = col >= row ? price[row-1] + temp[col-row] : 0;
                int skip = dp[col];
                temp[col] =  max(pick, skip);
            }
            dp = temp;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends