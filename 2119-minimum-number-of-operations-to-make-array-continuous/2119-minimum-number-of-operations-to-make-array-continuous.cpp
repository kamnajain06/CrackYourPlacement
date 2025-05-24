class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = n-1;
        int cnt = n;
        int i = 0, dup = 0;
        unordered_map<int,int> mpp;
        for(int j=0; j<n; j++){ 
            mpp[nums[j]]++;
            if(mpp[nums[j]] > 1){
                dup++;
            }
            while(nums[j] > nums[i] + k){
                if(mpp[nums[i]] > 1) dup--;
                mpp[nums[i]]--;
                i++;
            }
            // cout<<i + n-j - 1<<endl;
            cnt = min(cnt, i + n-j -1 + dup);
        }

        return cnt;
    }
};