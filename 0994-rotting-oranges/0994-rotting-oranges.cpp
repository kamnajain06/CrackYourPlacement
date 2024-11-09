class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS Traversal
        int direc[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }
        while(!q.empty()){
            int t = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            q.pop();
            for(int i=0; i<4; i++){
                int newRow = row + direc[i][0];
                int newCol = col + direc[i][1];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0){
                    grid[newRow][newCol] = 2;
                    visited[newRow][newCol] = 2;
                    q.push({{newRow,newCol},t+1});
                }
            }
            cnt = max(cnt, t);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};