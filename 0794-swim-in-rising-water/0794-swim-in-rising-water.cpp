class Solution {
public:
    int direc[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool isValid(int x, int y, int n){
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top(); 
            pq.pop();
            int x = pos.first, y = pos.second;

            if (visited[x][y]) continue;
            visited[x][y] = true;

            if (x == n - 1 && y == n - 1) return t;

            for (int k = 0; k < 4; ++k) {
                int nx = x + direc[k][0];
                int ny = y + direc[k][1];

                if (isValid(nx, ny, n) && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), {nx, ny}});
                }
            }
        }

        return -1; // Should not reach here
    }
};