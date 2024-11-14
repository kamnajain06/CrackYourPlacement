//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int> adj[], vector<int>& visited, vector<int> &path, vector<int> &safeNodes){
        visited[node] = 1;
        path[node] = 1;
        for(auto it:adj[node]){
            if(visited[it] == 0){
                if(dfs(it,adj,visited,path,safeNodes)){
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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> visited(V,0);
        vector<int> path(V,0);
        vector<int> safeNodes(V,0);
        for(int i=0; i<V; i++){
            if(visited[i] == 0){
                dfs(i,adj,visited,path,safeNodes);
            }
        }
        for(int i=0; i<V; i++){
            if(safeNodes[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends