class Solution {
public:
    // bool f(int i, int jump, vector<int>& stones, int n,
    //        unordered_map<int, int>& mpp, vector<vector<int>>& dp) {
    //     if (i >= n - 1)
    //         return true;

    //     if (dp[i][jump] != -1)
    //         return dp[i][jump];
    //     bool val = false;

    //     bool op1 =
    //         mpp.find(stones[i] + jump - 1) != mpp.end() &&
    //                 mpp[stones[i] + jump - 1] > i
    //             ? f(mpp[stones[i] + jump - 1], jump - 1, stones, n, mpp, dp)
    //             : false;
    //     bool op2 =
    //         mpp.find(stones[i] + jump) != mpp.end() && mpp[stones[i] + jump] > i
    //             ? f(mpp[stones[i] + jump], jump, stones, n, mpp, dp)
    //             : false;
    //     bool op3 =
    //         mpp.find(stones[i] + jump + 1) != mpp.end() &&
    //                 mpp[stones[i] + jump + 1] > i
    //             ? f(mpp[stones[i] + jump + 1], jump + 1, stones, n, mpp, dp)
    //             : false;

    //     val = op1 || op2 || op3;

    //     return dp[i][jump] = val;
    // }
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // if(stones[1] != 1) return false;
        // unordered_map<int, int> mpp;
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // for(int i=0; i<n; i++) mpp[stones[i]] = i;

        // return f(1, 1, stones, n, mpp, dp);

        if (stones[1] != 1)
            return false;
        unordered_map<int, int> mpp;
        vector<vector<int>> dp(n, vector<int>(n, false));
        for (int i = 0; i < n; i++)
            mpp[stones[i]] = i;
        
        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(!dp[i][j]) continue;
                for(int k = -1; k <= 1; k++){
                    if(j + k >= 0){
                        if(mpp.find(stones[i] + j + k) != mpp.end()){
                            dp[mpp[stones[i] + j + k]][j+k] = true;
                        }
                    }
                }
            }
        }

        for(int j=0; j<n; j++){
            if(dp[n-1][j] == 1) return true;
        }
        return false;
    }
};