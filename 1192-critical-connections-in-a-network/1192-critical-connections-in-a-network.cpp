class Solution {
public:
    int timer = 1;
    void dfs(int node, vector<int> &visited, vector<int> &low, vector<int> &tin, unordered_map<int, vector<int>> &mpp, vector<vector<int>> &ans, int parent){
        visited[node] = 1;
        low[node] = timer;
        tin[node] = timer;
        timer++; 
        for(auto it:mpp[node]){
            if(it == parent) continue;
            if(visited[it] == 0){
                dfs(it, visited, low, tin, mpp, ans, node);
                if(low[it] > tin[node]) ans.push_back({node,it});
            }
            low[node] = min(low[it], low[node]);
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> visited(n,0);
        unordered_map<int, vector<int>> mpp;
        for(auto it:connections){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }
        dfs(0,visited, low, tin, mpp, ans, -1);
        return ans;

    }
};