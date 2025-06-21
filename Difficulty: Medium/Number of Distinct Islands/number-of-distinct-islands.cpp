// User function Template for C++

class Solution {
  public:
    int direc[4][2] = {{0,1}, {0,-1}, {-1,0} , {1, 0}};
    bool isValid(int i , int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    void dfs(int i, int j, int &m, int &n, int &ref_x, int &ref_y, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<pair<int,int>> &v){
        vis[i][j] = 1;
        
        for(int it = 0; it < 4; it++){
            int x = i + direc[it][0];
            int y = j + direc[it][1];
            if(isValid(x, y, m, n) && vis[x][y] == 0 && grid[x][y] == 1){
                v.push_back({x-ref_x, y-ref_y});
                dfs(x, y, m, n, ref_x, ref_y, grid, vis, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> st;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int,int>> v;
                    v.push_back({0, 0});
                    dfs(i, j, m, n, i, j, grid, vis, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
