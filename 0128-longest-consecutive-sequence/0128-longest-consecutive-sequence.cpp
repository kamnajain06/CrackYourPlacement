class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp, visited;
        for(int i=0; i<n; i++) mpp[nums[i]]++;
        if(n <= 1) return n; 
        int maxi = 1, cnt = 1;
        for(auto [key, val]: mpp){
            if(mpp.find(key + 1) != mpp.end()){
                continue;
            }
            int temp = key - 1;
            while(mpp.find(temp) != mpp.end()){
                if(visited.find(temp) != visited.end()){
                    cnt += visited[temp];
                    break;
                }
                cnt++;
                temp--;
            }
            
            maxi = max(maxi, cnt);
            visited[key] = cnt;
            cnt = 1;
        }
        return maxi;
    }
};