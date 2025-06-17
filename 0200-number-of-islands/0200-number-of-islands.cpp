class Solution {
public:
    int direc[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0,1}};
    
    bool isValid(int i, int j, int m , int n){
        if( i >= m || j >= n || i < 0 || j < 0) return false;
        return true;
    }
    void dfs(int i, int j, int m , int n, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int x = i + direc[k][0];
            int y = j + direc[k][1];
            if(isValid(x, y, m, n) && grid[x][y] == '1' && vis[x][y] != 1){
                dfs(x, y, m, n, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;
                    dfs(i, j, m, n, grid, vis);
                }
            }
        }
        return cnt;
    }
};