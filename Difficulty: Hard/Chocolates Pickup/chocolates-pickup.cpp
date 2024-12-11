//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int fun(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
    //     if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    //     if(i == n-1){
    //         if(j1 == j2) return grid[i][j1];
    //         else return grid[i][j1]+grid[i][j2];
    //     }
        
    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
    //     int maxi = -1e8;
    //     for(int k1 = -1; k1 <= 1; k1++){
    //         for(int k2 = -1; k2 <= 1; k2++){
    //             maxi = j1 == j2 ? max(maxi, grid[i][j1] + fun(i+1, j1+k1, j2+k2, n, m, grid, dp)) :  max(maxi, grid[i][j1] + grid[i][j2] + fun(i+1, j1+k1, j2+k2, n, m, grid, dp));
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }
    int solve(int n, int m, vector<vector<int>>& grid) {
        
        // // Memoization
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
        // return fun(0, 0, m-1, n, m, grid, dp);
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i=n-2; i >= 0 ; i--){
            for(int j1= 0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int maxi = -1e8;
                    for(int k1 = -1; k1 <= 1; k1++){
                        for(int k2 = -1; k2 <= 1; k2++){
                            int val1 = -1e8;
                            int val2 = -1e8;
                            if(j1+k1 < m && j2 + k2 < m && j1+k1 >=0 && j2 + k2 >= 0){
                                val1 = grid[i][j1] + dp[i+1][j1+k1][j2+k2];
                                val2 = grid[i][j1] + grid[i][j2] + dp[i+1][j1+k1][j2+k2];
                            }
                            maxi = j1 == j2 ? max(maxi, val1) : max(maxi, val2);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends