class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto it : roads) {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> distance(n, LLONG_MAX), ways(n, 0);
        priority_queue<pair<long long , int>, vector<pair<long long , int>>, greater<pair<long long , int>>> pq;
        pq.push({0,0});
        distance[0] = 0;
        ways[0] = 1;
        long long mod = 1e9 + 7;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            long long dist = it.first;
            pq.pop();
            
            for(auto it: adjList[node]){
                if(it.second + dist == distance[it.first]){
                    ways[it.first] +=( ways[node])%mod;
                }
                if(it.second + dist < distance[it.first]){
                    distance[it.first] = dist + it.second;
                    ways[it.first] = ways[node];
                    pq.push({distance[it.first], it.first});
                }
            }
        }
        return ways[n-1]%mod;
    }
};