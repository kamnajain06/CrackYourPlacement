class Solution {
public:
//     int fun(int ind , int target ,vector<int>& nums, int n){
//         if(ind == n){
//             if(target == 0) return 1;
//             else return 0;
//         }

//         return fun(ind+1, target - nums[ind], nums, n) + fun(ind+1, target + nums[ind], nums, n);
//     }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int n = nums.size();
        // return fun(0, target, nums, n);
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == 0) cnt++;
            else break;
        }
        
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        if(cnt < n && nums[cnt] <= sum){
            dp[nums[cnt]] = 1;
        }
        for(int i=cnt+1; i<n; i++){
            vector<int> temp(sum+1, 0);
            temp[0] = 1;
            for(int j=1; j<=sum; j++){
                int pick = nums[i] <= j  ? dp[j - nums[i]] : 0;
                int skip = dp[j];
                temp[j] = pick + skip;
            }
            dp = temp;
        }

        int ans = 0;
        int i = 0;
        if(sum%2 == 0) i = sum/2;
        else i = (sum+1)/2;
        for(; i <= sum; i++){
            if(dp[i]){
                if((2*i-sum) == target || -(2*i-sum) == target ) ans+=dp[i];
            }
        }
        return (pow(2,cnt))*ans;
    }
};