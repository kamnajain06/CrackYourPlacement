class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> alpha(26,0);
        for(int i=0; i<n ; i++){
            alpha[abs('a'-s[i])]++;
        }
        sort(alpha.begin(), alpha.end());
        int ans = 0;

        for(int i=24; i>=0; i--){
            if(alpha[i] == 0) break;
            else if(alpha[i+1] == 0){
                ans += alpha[i];
                alpha[i] = 0;
            }
            else if(alpha[i] <= alpha[i+1]-1) continue;
            else{
                while(alpha[i] > 0 && alpha[i] > alpha[i+1]-1){
                    ans++;
                    alpha[i]--;
                }
            }
        }
        
        // unordered_map<char, int> mpp1;
        // for(auto it: mpp){
        //     int val = it.second;
        //     if(mpp1.find(val) == mpp1.end()) mpp1[it.second] = it.first;
        //     else{
        //         while(mpp1.find(val) != mpp1.end()){
        //             val--;
        //             ans++;
        //         }
        //         if(val > 0){
        //             mpp1[val] = it.first;
        //         }
        //     }   
        // }
        return ans;
    }
};