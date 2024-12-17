class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for(int i=0; i<n ; i++){
            mpp[s[i]]++;
        }
        int ans = 0;
        unordered_map<char, int> mpp1;
        for(auto it: mpp){
            int val = it.second;
            if(mpp1.find(val) == mpp1.end()) mpp1[it.second] = it.first;
            else{
                while(mpp1.find(val) != mpp1.end()){
                    val--;
                    ans++;
                }
                if(val > 0){
                    mpp1[val] = it.first;
                }
            }   
        }
        return ans;
    }
};