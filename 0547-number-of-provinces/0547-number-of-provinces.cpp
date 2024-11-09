class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<int>& visited){
        if(visited[node] == 1) return;
        visited[node] = 1;
        for(int i = 0 ; i< isConnected.size(); i++){
            if(isConnected[node][i] == 1 && visited[i] == 0){
                dfs(isConnected, i, visited);
            }
        }
        return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int cnt = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i] == 0){
                cnt++;
                dfs(isConnected, i, visited);
            }
        }
        return cnt;
    }
};