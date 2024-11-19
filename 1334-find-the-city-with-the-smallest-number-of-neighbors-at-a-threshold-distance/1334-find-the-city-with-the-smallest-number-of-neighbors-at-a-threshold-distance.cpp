class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cities(n, vector<int> (n, 1e9));
        for(auto it:edges){
            if(it[2] <= distanceThreshold){
                cities[it[0]][it[1]] = it[2];
                cities[it[1]][it[0]] = it[2];
            }
        }
        for(int via = 0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i == j) cities[i][j] = 0;
                    else{
                        cities[i][j] = min(cities[i][j], cities[i][via]+cities[via][j]);
                    }
                }
            }
        }
        int maxNode = INT_MIN;
        int minCount = INT_MAX;
        for(int i=0; i<n; i++){
            int cnt = 0;
            int node = i;
            for(int j=0; j<n; j++){
                if(cities[i][j] != 0 && cities[i][j] != 1e9 && cities[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= minCount){
                minCount = cnt;
                maxNode = max(maxNode,node);
            }
        }
        return maxNode;
    }
};