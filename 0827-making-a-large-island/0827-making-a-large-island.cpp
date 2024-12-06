class Solution {
public:
    int findParent(int x, vector<int> &parent){
	    if(parent[x] == x) return x;
	    return parent[x] = findParent(parent[x], parent);
	}
    void unionBySize(int u, int v, vector<int> &size, vector<int>&parent){
	    int parentU = findParent(u, parent);
	    int parentV = findParent(v, parent);
	    if(parentU == parentV) return;
	    if(size[parentU] == size[parentV]){
	        parent[parentV] = parentU;
	        size[parentU]++;
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
    void calculateSize(int n, int i, int j, vector<vector<int>> &grid, vector<int> &parent, vector<int> &size){
        int direc[4][2] = {{1,0},{0,1}, {-1,0}, {0,-1}};
        for(int it=0; it<4; it++){
            int x = i + direc[it][0];
            int y = j + direc[it][1];
            if(x < n && y < n && x >= 0 && y >= 0 && grid[x][y] == 1) {
                if(findParent(i*n+j, parent) != findParent(x*n+y, parent)){
                    unionBySize(i*n+j,x*n+y, size, parent);
                    calculateSize(n, x,y,grid, parent, size);
                }
            }            
        }
        return;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> size(n*n,1);
        vector<int> parent(n*n);

        vector<int> visited(n*n, 0);
        unordered_map<int,int> mpp;
        
        for(int i=0; i<n*n; i++){
            parent[i] = i;
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[findParent(i*n+j, parent)] == 0){
                    visited[i*n+j] = 1;
                    calculateSize(n,i,j, grid, parent,size);
                    if(size[i*n+j] == 0) mpp[i*n+j] = 1;
                    else mpp[i*n+j] = size[i*n+j];
                    
                }
            }
        }
        int ans = 0;
        for(auto it:mpp){
            // cout<<it.first<<","<<it.second<<endl;
            ans = max(ans, it.second);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sum = 1;
                unordered_set<int> st;
                if(grid[i][j] == 0){
                    int direc[4][2] = {{1,0},{0,1}, {-1,0}, {0,-1}};
                    for(int it=0; it<4; it++){
                        int x = i + direc[it][0];
                        int y = j + direc[it][1];
                        if(x < n && y < n && x >= 0 && y >= 0 && grid[x][y] == 1) {
                            st.insert(findParent(x*n+y, parent));
                        }            
                    }
                    for(auto it:st){
                        // cout<<it<<endl;
                        sum += mpp[it];
                    }
                }
                ans = max(ans, sum);
            }
        }


        return ans;

    }
};