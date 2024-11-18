class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector< pair<int,int>>> mpp;
        for(auto it:roads){
            mpp[it[0]].push_back({it[1],it[2]});
            mpp[it[1]].push_back({it[0],it[2]});

        }
        priority_queue<pair<long long, int> , vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> dist(n, LLONG_MAX), ways(n,0) ;
        q.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        vector<int> extra;
        int mod = (int) 1e9 + 7;
        while(!q.empty()){
            auto val = q.top();
            int node = val.second;
            long long distance = val.first;
            q.pop();
            for(auto it:mpp[node]){
                if(distance+it.second == dist[it.first]){
                    ways[it.first] = (ways[it.first] + ways[node])%(mod);
                }
                if(distance+it.second < dist[it.first]){
                    dist[it.first] = distance+it.second;
                    ways[it.first] = ways[node];
                    q.push({distance+it.second,it.first});
                }
            }
        }
        return ways[n-1]%mod;
    }
        
        
};