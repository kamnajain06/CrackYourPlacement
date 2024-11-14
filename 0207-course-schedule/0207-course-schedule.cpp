class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Topo sort using Kahn's Algo;
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> topo;
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]] += 1;
            mpp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int val = q.front();
            q.pop();
            topo.push_back(val);
            for(auto it:mpp[val]){
                if(indegree[it] != 0){
                    indegree[it] -= 1;
                    if(indegree[it] == 0) q.push(it);
                }
            }
        }
        return topo.size() == numCourses;
    }
};