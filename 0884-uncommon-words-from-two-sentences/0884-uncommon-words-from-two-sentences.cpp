class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mpp;
        vector<string> ans;
        int j=0;
        int i;
        s1 += ' ';
        s1.insert(s1.end(),s2.begin(), s2.end());
        for(i=0; i<s1.length(); i++){
            if(s1[i] == ' '){
                string s = s1.substr(j,i-j);
                mpp[s]++;
                j = i+1;
            }else if(i == s1.length()-1){
                mpp[s1.substr(j,i+1-j)]++;
            }
            
        }       
        for(auto it:mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }   
        
        return ans;
    }
};