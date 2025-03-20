class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }
    void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
        int parent_u = findParent(u, parent);
        int parent_v = findParent(v, parent);
        if (parent_u == parent_v)
            return;
        if (rank[parent_u] == rank[parent_v]) {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        } else if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        } else {
            parent[parent_v] = parent_u;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        unordered_map<int, vector<int>> mpp;
        unordered_map<int, int> weightsMpp;

        vector<int> parent(n, 0), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
            unionByRank(u, v, parent, rank);
        }

        unordered_map<int, int> componentAndValue;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int root = findParent(u, parent);
            if (componentAndValue.find(root) == componentAndValue.end()) {
                componentAndValue[root] = w;
            } else {
                componentAndValue[root] &= w;
            }
        }
        vector<int> ans;
        for (auto it : query) {
            if (findParent(it[0], parent) == findParent(it[1], parent)) {
                if (componentAndValue.find(findParent(it[0], parent)) !=
                    componentAndValue.end()) {
                    ans.push_back(componentAndValue[findParent(it[0], parent)]);
                } else {
                    ans.push_back(-1);
                }
            } else
                ans.push_back(-1);
        }
        return ans;
    }
};