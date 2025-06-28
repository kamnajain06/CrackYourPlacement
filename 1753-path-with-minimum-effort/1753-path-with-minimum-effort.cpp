class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int direc[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        vector<vector<int>> efforts(n , vector<int> (m, INT_MAX));
        q.push({0,{0,0}});
        efforts[0][0] = 0;
        while(!q.empty()){
            auto it = q.top();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x == n-1 && y == m-1) return diff;
            q.pop();
            for(int i=0; i<4; i++){
                int X = x + direc[i][0];
                int Y = y + direc[i][1];
                if(X >= 0 && X < n && Y >= 0 && Y < m){
                    int newDiff = max(abs(heights[X][Y] - heights[x][y]), diff);
                    if(newDiff < efforts[X][Y]){
                        efforts[X][Y] = newDiff;
                        q.push({newDiff,{X,Y}});
                    }
                }
            }
        }
        return 0;
    }
};