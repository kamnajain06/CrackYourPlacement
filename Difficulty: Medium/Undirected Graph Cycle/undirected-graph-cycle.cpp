//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        queue<pair<int,int>> q;
        int n = adj.size();
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                q.push({i,-1});
                visited[i] = 1;
                while(!q.empty()){
                    int val = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto it:adj[val]){
                        if(visited[it] == 0){
                            q.push({it,val});
                            visited[it] = 1;
                        }else if(it != parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends