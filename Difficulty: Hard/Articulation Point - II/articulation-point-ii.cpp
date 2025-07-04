class Solution {
  public:
    int timer = 1;
    set<int> s;
    void dfs(int node, int par, vector<int> &tin, vector<int> &low, vector<int> &vis, unordered_map<int, vector<int>> &adjList){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        int child = 0;
        for(auto it: adjList[node]){
            if(it == par) continue;
            if(!vis[it]){
                child++;
                dfs(it, node, tin, low, vis, adjList);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && par != -1){
                    s.insert({node});
                }
            }else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && par == -1) s.insert(node);
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adjList;
        for(auto it: edges){
            adjList[it[1]].push_back(it[0]);
            adjList[it[0]].push_back(it[1]);
        }
        vector<int> vis(V, 0), tin(V), low(V);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, tin, low, vis, adjList);
            }
        }
        if(s.empty()) return {-1};
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};