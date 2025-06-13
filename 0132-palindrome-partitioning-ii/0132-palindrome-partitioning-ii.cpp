class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else return false;
        }
        return true;
    }
    // int f(int i, int prev, int n, string &s, vector<vector<int>> &dp){
    //     if(i > n){
    //         if(prev >= n) return 0;
    //         return 1e9;
    //     }
    //     if(dp[i][prev] != -1) return dp[i][prev];
    //     string st = s.substr(prev, i-prev);
    //     int take = 1e9;
    //     int skip = f(i+1, prev, n, s, dp);
    //     if(isPalindrome(st)){
    //         take = 1 + f(i+1, i, n, s, dp);
    //     }

    //     return dp[i][prev] = min(take, skip);
    // }
    int f(int i, int n, string &s, vector<int> &dp, vector<vector<bool>> &p){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int mini = 1e7;
        for(int j = i; j<n; j++){
            if(p[i][j]){
                mini = min(1 + f(j+1, n, s, dp, p), mini);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        vector<vector<bool>> p(n, vector<bool> (n, false));
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j = i; j<n; j++){
                temp += s[j];
                if(isPalindrome(temp)) p[i][j] = true;
            }
        }
        return f(0, n, s, dp, p)-1;

        // vector<int> dp(n+1, 1e9);
        // dp[n] = 0;
        // vector<int> curr(n+1, 1e9);
        // for(int i = n; i>=0; i--){
        //     for(int j = 0; j<n; j++){
        //         string st = s.substr(j, i-j);
        //         int take = 1e9;
        //         int skip = dp[j];
        //         if(isPalindrome(st)){
        //             take = 1 + dp[i];
        //         }
        //         curr[j] = min(take, skip);
        //     }
        //     dp = curr;
        // }
        // return dp[0] - 1;
    }
};