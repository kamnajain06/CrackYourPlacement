class Solution {
public:
    // long long fun(int ind, int n, vector<vector<int>>& questions,
    //               vector<long long>& dp) {
    //     if (ind >= n)
    //         return 0;

    //     if (dp[ind] != -1)
    //         return dp[ind];

    //     long long solve = questions[ind][0] +
    //                       fun(ind + questions[ind][1] + 1, n, questions, dp);
    //     long long skip = fun(ind + 1, n, questions, dp);

    //     return dp[ind] = max(solve, skip);
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // vector<long long> dp(n, -1);
        // return fun(0, n, questions, dp);

        vector<long long> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long solve = i + questions[i][1] + 1 < n ? questions[i][0] + dp[i + (questions[i][1] + 1)] : questions[i][0];
            long long skip = i + 1 < n ? dp[i + 1] : 0;

            dp[i] = max(solve, skip);
        }
        return dp[0];
    }
};