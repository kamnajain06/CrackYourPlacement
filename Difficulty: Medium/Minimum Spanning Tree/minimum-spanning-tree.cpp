class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // unordered_map<int, vector<pair<int,int>>> mpp;
        // for(auto it: adj){
        //     mpp[it[0]].push_back({it[1], it[2]});
        //     mpp[it[1]].push_back({it[0], it[2]});
        // }
        priority_queue< pair< int, int> , vector<pair<int, int>> , greater< pair<int,int>> > pq;
        vector<int> visited(V, 0);
        
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            
            // cout << wt << " , " << node << endl;
            pq.pop();
            
            if(!visited[node]){
                visited[node] = 1;
                sum += wt;
                for(auto it: adj[node]){
                     pq.push({it[1], it[0]});
                }
            }
            
        }
        return sum;
        
    }
};