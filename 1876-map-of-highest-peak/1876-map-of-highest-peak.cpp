class Solution {
public:
    int direc[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0,1}};
    bool isValid(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue< pair< pair<int, int>, int > > q;
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int val = q.front().second;
            q.pop();

            ans[i][j] = val;

            for(int k = 0; k < 4; k++){
                int x = i + direc[k][0];
                int y = j + direc[k][1];
                if(isValid(x, y, m, n) && vis[x][y] == 0){
                    vis[x][y] = 1;
                    q.push({{x,y}, val+1});
                }
            }

        }
        return ans;
    }
};