//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        vector<vector<int>> visited(n,vector<int> (m,0));
        
        int direc[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            ans[x][y] = cnt;
            
            for(int i=0; i<4; i++){
                int newX = x + direc[i][0];
                int newY = y + direc[i][1];
                if(newX >= 0 && newX < n && newY >=0 && newY < m && visited[newX][newY] == 0){
                    q.push({{newX,newY}, cnt+1});
                    visited[newX][newY] = 1;
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends