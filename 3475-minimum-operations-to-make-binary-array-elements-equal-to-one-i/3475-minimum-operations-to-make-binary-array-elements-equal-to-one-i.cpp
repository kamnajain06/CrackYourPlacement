class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> mpp;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                mpp.insert(i);
            }
        }
        if(mpp.empty()) return 0;
        int cnt = 0;
        if(mpp.size() < 2) return -1;
        while(!mpp.empty()){
            int i = *mpp.begin();
            if(i + 3 > n) return -1;
            for(int j = i; j < i+3 && j < n; j++){
                if(nums[j] == 0){
                    mpp.erase(j);
                }else{
                    mpp.insert(j);
                }
                nums[j] ^= 1;
            }
            cnt++;
        }
        return cnt;
    }
};