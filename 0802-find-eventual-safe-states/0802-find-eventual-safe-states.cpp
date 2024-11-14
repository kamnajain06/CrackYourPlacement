class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<int>& visited, vector<int> &path, vector<int> &safeNodes){
        visited[node] = 1;
        path[node] = 1;
        for(auto it:graph[node]){
            if(visited[it] == 0){
                if(dfs(it,graph,visited,path,safeNodes)){
                    return true;
                }
            }else if(visited[it] == 1 && path[it] == 1){
                return true;
            }
        }
        safeNodes[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> visited(n,0);
        vector<int> path(n,0);
        vector<int> safeNodes(n,0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i,graph,visited,path,safeNodes);
            }
        }
        for(int i=0; i<n; i++){
            if(safeNodes[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};