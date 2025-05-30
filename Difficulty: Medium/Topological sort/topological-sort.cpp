//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

// Kahn's Algorithm -> BFS with indegree
    // vector<int> topologicalSort(vector<vector<int>>& adj) {
    //     queue<int> q;
    //     vector<int> ans;
    //     vector<int> indegree(adj.size(),0);
    //     for(int i=0; i<adj.size(); i++){
    //         for(auto it:adj[i]){
    //             indegree[it]+=1;
    //         }
    //     }
    //     for(int i=0; i<adj.size(); i++){
    //         if(indegree[i] == 0) q.push(i);
    //     }
    //     while(!q.empty()){
    //         int val = q.front();
    //         ans.push_back(val);
    //         q.pop();
    //         for(auto it:adj[val]){
    //             if(indegree[it] != 0){
    //                 indegree[it] -= 1;
    //                 if(indegree[it] == 0){
    //                     q.push(it);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

// Basic DFS
  void dfs(int node,vector<vector<int>>& adj, vector<int> &visited, stack<int> &st){
          visited[node] = 1;
          for(auto it:adj[node]){
              if(visited[it] == 0){
                  dfs(it,adj,visited,st);
              }
          }
          st.push(node);
          return;
      }
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          vector<int> ans;
          stack<int> st;
          vector<int> visited(adj.size(),0);
          
          for(int i=0; i<adj.size(); i++){
              if(visited[i] == 0){
                  dfs(i,adj,visited,st);
              }
          }
          while(!st.empty()){
              ans.push_back(st.top());
              st.pop();
          }
          return ans;
      }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
