//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
// Using Priority Queue
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(adj.size(),INT_MAX);
        q.push({src,0});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.top().first;
            int distance = q.top().second;
            q.pop();
            for(auto it:adj[node]){
                dist[it.first] = min(dist[it.first],distance+it.second);
                if(dist[it.first] == distance+it.second) q.push({it.first,distance+it.second});
            }
        }
        for(int i=0; i<adj.size(); i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
      
// Using Set (most efficient since it removes the unnecessary elements)
        // set<pair<int,int>> st;
        // vector<int> dist(adj.size(),INT_MAX);
        // st.insert({0,src});
        // dist[src] = 0;
        // while(!st.empty()){
        //     auto val = *(st.begin());
        //     int node = val.second;
        //     int distance = val.first;
        //     st.erase(val);
        //     for(auto it:adj[node]){
        //         if(distance+it.second < dist[it.first]){
        //             if(dist[it.first] != INT_MAX) st.erase({dist[it.first],it.first});
        //             dist[it.first] = distance+it.second;
        //             st.insert({distance+it.second,it.first});
        //         }
        //     }
        // }
        // return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
