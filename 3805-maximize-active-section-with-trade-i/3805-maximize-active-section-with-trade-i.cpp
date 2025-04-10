class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        int cnt = 0;
        int ones = 0;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0') {
                cnt++;
                right[i] = cnt;
            } else {
                cnt = 0;
                right[i] = right[i - 1];
                ones++;
            }
        }
        if(s[n-1]== '1') ones++;
        int ans = ones;
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i + 1] == '0') {
                cnt++;
                left[i] = cnt;
            } else {
                cnt = 0;
                left[i] = left[i+1];
            }
        }
        // for(auto it:right) cout<<it<<endl;

        int i = 0;
        while (i < n) {
            if(s[i] == '0'){
                int j = i+1;
                while(j < n && s[j] == '1') j++;
                
                if(j < n && j != i+1){
                    // cout<<j<<endl;
                    ans = max(ans, ones + left[j-1] + right[j-1]);
                    i = j;
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
        
        
        return ans ;
    }
};