//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> parent(n+1,0);
        vector<int>dist(n+1,INT_MAX);
        ans.push_back(-1);
        unordered_map<int, vector<pair<int,int>>> mpp;
        if(m == 0) return ans;
        for(int i=0; i<m; i++){
            mpp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            mpp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,1});
        dist[1] = 0;
        while(!q.empty()){
            auto val = q.top();
            int node = val.second;
            int distance = val.first;
            q.pop();
            for(auto it: mpp[node]){
                if(dist[it.first] > it.second+distance){
                    parent[it.first] = node;
                    dist[it.first] = it.second+distance;
                    q.push({dist[it.first],it.first});        
                }
            }        
        }
        if(dist[n] == INT_MAX) return ans;
        ans[0] = dist[n];
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin()+1, ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends