class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if((sum+d) % 2 != 0) return 0;
        vector<vector<int>> dp(n, vector<int> ((sum+d)/2 + 1, 0));
        dp[0][0] = 1;
        if (arr[0] <= (sum+d)/2 ) dp[0][arr[0]] += 1;
        
        for(int i=1; i<n; i++){
            for(int k = 0; k <= (sum+d)/2; k++){
                int take = k-arr[i] >= 0 ?dp[i-1][k-arr[i]] : 0;
                int skip = dp[i-1][k];
                
                dp[i][k] = take + skip;
            }
        }
    
        return dp[n-1][(sum+d)/2];
    }
};