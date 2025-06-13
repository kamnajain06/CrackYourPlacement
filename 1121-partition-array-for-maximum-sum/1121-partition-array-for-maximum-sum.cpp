class Solution {
public:
    int f(int i, int n, vector<int> &arr, int k, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int val = arr[i];
        int sum = 0;
        for(int j=i; j<i+k && j < n; j++){
            val = max(val, arr[j]);
            sum = max(val*(j-i+1) + f(j+1, n, arr, k, dp), sum);
        }
        return dp[i] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, n, arr, k, dp);
    }
};