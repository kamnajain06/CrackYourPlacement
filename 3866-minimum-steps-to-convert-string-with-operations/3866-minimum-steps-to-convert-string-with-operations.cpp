class Solution {
public:
    int ans(string s, string t){
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == t[i]) continue;
            // greedily swap
            for(int j = i+1; j<n; j++){
                if(s[i] == t[j] && t[i] == s[j]){
                    swap(s[i], s[j]);
                    cnt++;
                    break;
                }
            }
            if(s[i] != t[i]){
                s[i] = t[i];
                cnt++;
            }
        }
        return cnt;
    }
    int minOperations(string word1, string word2) {
        int n = word1.length();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j>=0; j--){
                string sub1 = word1.substr(j, i-j);
                string sub2 = word2.substr(j, i-j);

                dp[i] = min(dp[i], dp[j] + ans(sub1, sub2));
                reverse(sub1.begin(), sub1.end());
                dp[i] = min(dp[i], dp[j] + 1 + ans(sub1, sub2));
            }
        }
        return dp[n];
    }
};