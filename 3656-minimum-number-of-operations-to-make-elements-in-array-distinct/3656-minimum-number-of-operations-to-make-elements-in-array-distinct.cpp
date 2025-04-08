class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> freqMpp, remMpp;
        for (int i = 0; i < n; i++) {
            freqMpp[nums[i]]++;
        }
        for (auto it : freqMpp)
            if(it.second > 1){
                remMpp[it.first] = it.second;
            }

        int left = 0;
        while (left < n) {
            if (remMpp.empty())
                return ans;
            else ans++;
            for (int i = 0; i < 3; i++) {
                if (left + i < n) {
                    if (remMpp.find(nums[left + i]) != remMpp.end()) {
                        remMpp[nums[left + i]]--;
                        if (remMpp[nums[left + i]] <= 1) {
                            remMpp.erase(nums[left + i]);
                        }
                    }
                } else
                    return ans;
            }
            
            left = left + 3;
        }
        return ans;
    }
};