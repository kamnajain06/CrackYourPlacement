class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // set<int> mpp;
        // for(int i=0; i<n; i++){
        //     if(nums[i] == 0){
        //         mpp.insert(i);
        //     }
        // }
        // if(mpp.empty()) return 0;
        // int cnt = 0;
        // if(mpp.size() < 2) return -1;
        int i = 0, cnt = 0;
        while(i < n-2){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                cnt++;
            }
            i++;
            
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum == n) return cnt;
        return -1;
    }
};