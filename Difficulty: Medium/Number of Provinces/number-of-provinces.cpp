//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     void dfs(vector<vector<int>>& adj, int node, vector<int>& visited){
            if(visited[node] == 1) return;
            visited[node] = 1;
            for(int i = 0 ; i< adj.size(); i++){
                if(adj[node][i] == 1 && visited[i] == 0){
                    dfs(adj, i, visited);
                }
            }
            return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(adj.size(), 0);
        int cnt = 0;
        for(int i=0; i<adj.size(); i++){
            if(visited[i] == 0){
                cnt++;
                dfs(adj, i, visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends