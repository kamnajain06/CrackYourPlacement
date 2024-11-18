class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector< pair<int,int>>> mpp;
        for(auto it:times){
            mpp[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(n+1, INT_MAX);
        q.push({0,k});
        dist[k] = 0;
        while(!q.empty()){
            auto val = q.top();
            int node = val.second;
            int distance = val.first;
            cout<<distance<<endl;
            q.pop();
            for(auto it:mpp[node]){
                if(distance+it.second < dist[it.first]){
                    dist[it.first] = distance+it.second;
                    q.push({distance+it.second,it.first});
                }
            }
        }
        int ans = 0;
        dist[0] = -1;
        for(auto it:dist){
            if(ans < it){
                ans = it;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};