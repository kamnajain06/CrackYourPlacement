class Solution {
public:
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void unionByRank(int u, int v, vector<int> &rank, vector<int> &parent){
        int parentU = findParent(u, parent);
        int parentV = findParent(v, parent);
        if(rank[parentU] == rank[parentV]){
            parent[parentV] = parentU;
            rank[parentU]++;
        }else if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        }else{
            parent[parentV] = parentU;
        }
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        unordered_map<string, int> mpp;
        int n = accounts.size();
        vector<int> rank(n,0);
        vector<int> parent(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mpp.find(accounts[i][j]) == mpp.end()){
                    mpp[accounts[i][j]] = i;
                }else{
                    unionByRank(mpp[accounts[i][j]], i, rank, parent);
                }
            }
        }
        for(auto i:parent) cout<<i<<endl;
        unordered_map<int, set<string>> temp;
        for(auto it: mpp){
            temp[findParent(it.second, parent)].insert(it.first);
        }
        
        for(auto it: temp){
            vector<string> v;
            v.push_back(accounts[it.first][0]);
            for(auto i:it.second){
                v.push_back(i);
            }
            ans.push_back(v);
        }
        return ans;
    }
};