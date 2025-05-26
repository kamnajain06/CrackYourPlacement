class Solution {
public:
    // int f(int n, vector<int> &dp){
    //     if(n <= 3) return n;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = f(n-1, dp) + f(n-2, dp);
    // }
    int climbStairs(int n) {
        //  < recursion >
        // if(n <= 3) return n;
        // return climbStairs(n-1) + climbStairs(n-2);

        // < memo >
        // vector<int> dp(n+1, -1);
        // return f(n, dp);

        // < tab >
        vector<int> dp(n+1, 0);
        if(n < 3) return n;
        int prev2 = 1, prev1 = 2;

        for(int i=3; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};