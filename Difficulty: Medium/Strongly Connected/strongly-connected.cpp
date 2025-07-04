//Position this line where user code will be pasted.
class Solution {
  public:
    stack<int> s;
    void dfs(int node,vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
        s.push(node);
    }
    void dfs1(int node, unordered_map<int, vector<int>> &adjList, vector<int> &vis1){
        vis1[node] = 1;
        for(auto it: adjList[node]){
            if(!vis1[it]){
                dfs1(it, adjList, vis1);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i<adj.size(); i++){
            for(auto it: adj[i]){
                adjList[it].push_back(i);
            }
        }
        vector<int> vis1(n, 0);

        int cnt = 0;
        // cout << s.size() << endl;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis1[node]){
                cnt++;
                dfs1(node, adjList, vis1);
            }
        }
        
        return cnt;
        
    }
};