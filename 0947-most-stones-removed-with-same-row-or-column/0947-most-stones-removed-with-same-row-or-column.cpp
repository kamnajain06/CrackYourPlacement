class Solution {
public:
    int findParent(int x, vector<int> &parent){
	    if(parent[x] == x) return x;
	    return parent[x] = findParent(parent[x], parent);
	}
	// void unionByRank(int u, int v, vector<int> &rank, vector<int>&parent){
	//     int parentU = findParent(u, parent);
	//     int parentV = findParent(v, parent);
	//     if(parentU == parentV) return;
	//     if(rank[parentU] == rank[parentV]){
	//         parent[parentU] = parentV;
	//         rank[parentV]++;
	//     }
	//     else if(rank[parentU] < rank[parentV]){
	//         parent[parentU] = parentV;
	//     }else{
	//         parent[parentV] = parentU;
	//     }
	//     return;
	// }
    void unionBySize(int u, int v, vector<int> &size, vector<int>&parent){
	    int parentU = findParent(u, parent);
	    int parentV = findParent(v, parent);
	    if(parentU == parentV) return;
	    if(size[parentU] == size[parentV]){
	        parent[parentU] = parentV;
	        size[parentV]++;
	    }
	    else if(size[parentU] < size[parentV]){
	            parent[parentU] = parentV;
	            size[parentV] += size[parentU];
	    }else{
	        parent[parentV] = parentU;
	        size[parentU] += size[parentV];
	    }
	    return;
	}
    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        int m = 0;
        for(auto it:stones){
            m = max(m, it[0]);
            n = max(n, it[1]);  
        }
        m+=1;
        n+=1;
        vector<int> size(m+n,0);
        vector<int> parent(m+n);
        for(int i=0; i<m+n; i++){
            parent[i] = i;
        }
        for(auto it: stones){
            if(findParent(it[0], parent) != findParent(it[1]+m, parent)){
                unionBySize(it[0], it[1]+m, size, parent);
            }
        }
        int cnt = 0;
        for(int i=0; i<parent.size(); i++){
            if(parent[i] == i && size[i] >= 1){
                cnt++;
            }
        }
        cout<<cnt<<endl;
        return stones.size()-cnt;
    }
};