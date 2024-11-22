class Solution {
public:
    int findParent(int node, vector<int> & parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void unionByRank(int u, int v, vector<int> &rank, vector<int> &parent){
        int par_u = findParent(u, parent);
        int par_v = findParent(v, parent);
        if(rank[par_u] == rank[par_v]){
            parent[par_v] = par_u;
            rank[par_u]++;
        }else if(rank[par_u] < rank[par_v]){
            parent[par_u] = par_v;
        }else{
            parent[par_v] = par_u;
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int cnt = 0;
        int extraCnt = 0;
        for(int i=0; i<connections.size(); i++){
            if(findParent(connections[i][0],parent) != findParent(connections[i][1],parent)){
                unionByRank(connections[i][0], connections[i][1], rank ,parent);
            }else{
                cnt++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(parent[i] == i) extraCnt++;
            if(extraCnt-1 > cnt) return -1;
        }
        return extraCnt-1;
    }
};