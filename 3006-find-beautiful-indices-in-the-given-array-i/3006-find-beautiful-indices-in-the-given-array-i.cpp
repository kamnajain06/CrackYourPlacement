class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> avec;
        vector<int> bvec;

        int i = 0, j=0; 
        for(int it=0; it<s.length(); it++){
            if(s[it] == a[i]){
                if(s.substr(it, a.length()) == a) avec.push_back(it);
            }
            if(s[it] == b[j]){
                if(s.substr(it, b.length()) == b) bvec.push_back(it);
            }
        }
        vector<int> ans;
        for(auto it:avec){
            for(auto i:bvec){
                if(abs(it-i) <= k){
                    ans.push_back(it);
                    break;
                }
                
            }
        }
        return ans;
    }
};