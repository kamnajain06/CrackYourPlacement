class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(n, 0);
        visited[src] = 1;
        pq.push({0, src});
        
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            distances[node] = min(distances[node], dist);
            pq.pop();
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    pq.push({dist+1, it});
                }
            }
        }
        
        for(auto &it: distances) if(it == INT_MAX) it = -1;
        return distances;
    }
};