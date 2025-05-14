class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n; j++){
                if(j - 1 > i && nums[j] == nums[j-1]) continue;
                for(int k=j+1; k<n; k++){
                    if(k - 1 > j && nums[k] == nums[k-1]) continue;
                    long long val = (long long) target-(long long)nums[i]-(long long)nums[j]-(long long) nums[k];
                    if(val > INT_MAX || val < INT_MIN) continue;
                    if(mpp.find(val) != mpp.end() && mpp[val] > i && mpp[val] > j && mpp[val] > k){
                        cout<<mpp[val]<<endl;
                        ans.push_back({nums[i], nums[j], nums[k], (int)val});
                    }
                }
            }
        }
        return ans;
    }
};