//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int,set<pair<int,int>>> mpp;
        queue<pair<int,int>> q;
        vector<int> dist(V,INT_MAX);
        for(int i=0; i<E; i++){
            mpp[edges[i][0]].insert({edges[i][1],edges[i][2]});
        }
        q.push({0,0});
        dist[0] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(auto it: mpp[node]){
                dist[it.first] = min(dist[it.first],distance+it.second);
                if(dist[it.first] == distance+it.second) q.push({it.first,dist[it.first]});
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends