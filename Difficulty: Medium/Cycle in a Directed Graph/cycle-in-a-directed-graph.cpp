//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    // bool isCyclic(int V, vector<vector<int>> adj) {
    //     // Using Kahn's Algorithm
    //     vector<int> topo;
    //     queue<int> q;
    //     vector<int> indegree(V,0);
        
    //     for(int i=0; i<V; i++){
    //         for(auto it:adj[i]){
    //             indegree[it]+=1;
    //         }
    //     }
    //     for(int i=0; i<V; i++){
    //         if(indegree[i] == 0) q.push(i);
    //     }
    //     while(!q.empty()){
    //         int val = q.front();
    //         q.pop();
    //         topo.push_back(val);
    //         for(auto it:adj[val]){
    //             if(indegree[it]!=0){
    //                 indegree[it] -= 1;
    //                 if(indegree[it] == 0) q.push(it);
    //             }
    //         }
    //     }
    //     return topo.size() != V;
    // }

    bool dfs(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVisited){
          visited[node] = 1;
          pathVisited[node] = 1;
          for(auto it: adj[node]){
              if(visited[it] == 0){
                  if(dfs(it,adj,visited,pathVisited)) return true;
              }else if(visited[it] == 1 && pathVisited[it] == 1) return true;
          }
          pathVisited[node] = 0;
          return false;
      }
      bool isCyclic(int V, vector<vector<int>> adj) {
          vector<int> visited(V,0);
          vector<int> pathVisited(V,0);
          
          for(int i=0; i<V; i++){
              if(visited[i] == 0){
                  if(dfs(i,adj,visited,pathVisited)) return true;
              }
          }
          return false;
      }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
