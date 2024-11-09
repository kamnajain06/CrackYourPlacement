//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void dfs(vector<vector<int>>& adj, int node, vector<int> &visited, vector<int> &ans){
        visited[node] = 1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(visited[it] == 0){
                dfs(adj,it,visited,ans);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<int> visited(adj.size(), 0);
        dfs(adj, 0, visited, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends