class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        unordered_map<int, vector<pair<int,int>>> mpp;
        for(int i=0; i<flights.size(); i++){
            mpp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            int price = it.first;
            int node = it.second.first;
            int stops = it.second.second;
            q.pop();
            for(auto itr: mpp[node]){
                if(itr.second + price < dist[itr.first]){
                    dist[itr.first] = itr.second + price;
                    if(itr.first != dst){
                        if(stops+1 <= k){
                            q.push({dist[itr.first],{itr.first, stops+1}});
                        }
                    }else q.push({dist[itr.first],{itr.first, stops}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};