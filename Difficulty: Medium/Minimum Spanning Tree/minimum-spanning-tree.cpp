class Solution {
  public:
    int findParent(int x, vector<int> &parent){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
        int par_u = findParent(u, parent);
        int par_v = findParent(v, parent);
        if(par_u == par_v) return;
        if(rank[par_u] == rank[par_v]){
            parent[par_u] = par_v;
            rank[par_v]++;
        }else if(rank[par_u] < rank[par_v]){
            parent[par_u] = par_v;
        }else{
            parent[par_v] = par_u;
        }
    }
    void unionBySize(int u, int v, vector<int> &parent, vector<int> &size){
        int par_u = findParent(u, parent);
        int par_v = findParent(v, parent);
        if(par_u == par_v) return;
        if(size[par_u] <= size[par_v]){
            parent[par_u] = par_v;
            size[par_v]+= size[par_u];
        }else{
            size[par_u]+= size[par_v];
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Prim's Algorithm
        
        // unordered_map<int, vector<pair<int,int>>> mpp;
        // for(auto it: adj){
        //     mpp[it[0]].push_back({it[1], it[2]});
        //     mpp[it[1]].push_back({it[0], it[2]});
        // }
        // priority_queue< pair< int, int> , vector<pair<int, int>> , greater< pair<int,int>> > pq;
        // vector<int> visited(V, 0);
        
        // pq.push({0, 0});
        // int sum = 0;
        // while(!pq.empty()){
        //     int wt = pq.top().first;
        //     int node = pq.top().second;
            
        //     // cout << wt << " , " << node << endl;
        //     pq.pop();
            
        //     if(!visited[node]){
        //         visited[node] = 1;
        //         sum += wt;
        //         for(auto it: adj[node]){
        //              pq.push({it[1], it[0]});
        //         }
        //     }
            
        // }
        // return sum;
        
        // Kruskal's algorithm
        
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                pq.push({it[1], {i, it[0]}});
            }
        }
        vector<int> parent(V, 0);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(V, 0), size(V, 1);
        
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(findParent(u, parent) != findParent(v, parent)){
                sum += wt;
                // unionByRank(u, v, parent, rank);
            }
        }
        return sum;
    }
};