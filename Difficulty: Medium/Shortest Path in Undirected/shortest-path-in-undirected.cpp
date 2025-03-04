//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<edges.size(); i++){
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        vector<int> dist(N,INT_MAX);
        q.push({src,0});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(auto it:mpp[node]){
                dist[it] = min(dist[it],distance+1);
                if(dist[it] == distance+1) q.push({it,distance+1});
            }
        }
        for(int i=0; i<N; i++){
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends