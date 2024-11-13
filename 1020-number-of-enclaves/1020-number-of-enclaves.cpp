class Solution {
public:
    void dfs(int n, int m,int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited){
        int direc[4][2]= {{1,0}, {0,1}, {0,-1},{-1,0}};
        visited[row][col] = 1;
        for(int i=0; i<4; i++){
            int newRow = row + direc[i][0];
            int newCol = col + direc[i][1];
            if(newRow >= 0 && newRow<n && newCol >=0 && newCol < m && visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1 ){
                visited[newRow][newCol] = 1;
                dfs(n,m,newRow,newCol,grid,visited);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int j=0; j<m; j++){
           if(grid[0][j] == 1 && visited[0][j] == 0){
               dfs(n,m,0,j,grid,visited);
           } 
           if(grid[n-1][j] == 1 && visited[n-1][j] == 0){
               dfs(n,m,n-1,j,grid,visited);
           } 
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && visited[i][0] == 0){
               dfs(n,m,i,0,grid,visited);
           } 
           if(grid[i][m-1] == 1 && visited[i][m-1] == 0){
               dfs(n,m,i,m-1,grid,visited);
           }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};