class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string a, string b){
            return a.length() < b.length();
        });
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(words[i].length() == words[j].length() + 1){
                    int l = 0, r = 0;
                    while(l < words[i].length() && r < words[j].length()){
                        if(words[i][l] == words[j][r]){
                            l++;
                            r++;
                        }else{
                            l++;
                        }
                    }
                    if(l <= words[i].length() && r == words[j].length()){
                        if(dp[i] < 1+ dp[j]){
                            dp[i] = 1+dp[j];
                            maxi = max(maxi, dp[i]);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};