class Solution {
public:
    // int f(int ind, int n , vector<int> &cost){
    //     if(ind >= n) return 0;
    //     return cost[ind] + min(f(ind + 1, n, cost), f(ind + 2, n, cost));
    // }

    // int f(int ind, int n , vector<int> &cost, vector<int> &dp){
    //     if(ind >= n) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     return dp[ind] = cost[ind] + min(f(ind + 1, n, cost, dp), f(ind + 2, n, cost, dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // < recursion >
        // if(n == 2) return min(cost[0], cost[1]);
        // return min(f(0, n, cost), f(1, n, cost));

        // < memo >
        // vector<int> dp(n+1, -1);
        // if(n == 2) return min(cost[0], cost[1]);
        // return min(f(0, n, cost, dp), f(1, n, cost, dp));

        // < Tab >
        vector<int> dp(n+1, 0);

        for(int i=2; i<=n; i++){
            dp[i] = min(cost[i-1] + dp[i-1] , cost[i-2] + dp[i-2]);
        }
        return dp[n];

        
    }
};