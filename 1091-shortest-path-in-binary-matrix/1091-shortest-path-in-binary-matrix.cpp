class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        priority_queue< pair< int, pair<int,int>>, vector<pair< int, pair<int,int>>>, greater<pair< int, pair<int,int>>>> q;
        if(grid[0][0] != 0) return -1;
        q.push({1,{0,0}});
        dist[0][0] = 1;
        int direc[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        while(!q.empty()){
            auto it = q.top();
            int row = it.second.first;
            int col = it.second.second;
            int distance = it.first;
            q.pop();
            for(int i=0; i<8; i++){
                int newRow = row + direc[i][0];
                int newCol = col + direc[i][1];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < n && grid[newRow][newCol] == 0){
                    if(dist[newRow][newCol] > distance + 1){
                        dist[newRow][newCol] = distance + 1;
                        q.push({dist[newRow][newCol], {newRow,newCol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};