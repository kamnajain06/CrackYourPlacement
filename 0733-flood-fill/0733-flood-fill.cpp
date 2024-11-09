class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int direc[4][2]= {{1,0},{0,1}, {0,-1}, {-1,0}};
        vector<vector<int>> visited(n, vector<int> (m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int clr = image[sr][sc];
        if(clr == color) return image;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = color;
            for(int i=0; i<4; i++){
                int newRow = row + direc[i][0];
                int newCol = col + direc[i][1];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] == 0 && image[newRow][newCol] == clr){
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }
        return image;

    }
};