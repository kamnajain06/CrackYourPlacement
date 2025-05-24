class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        unordered_map<char, vector<int>> mpp;

        for(int i=0; i<n; i++){
            mpp[word[i]].push_back(i);
        }

        vector<pair<int,int>> s;

        for(int i=0; i<n; i++){
            int start = i;
            auto it = lower_bound(mpp[word[i]].begin(), mpp[word[i]].end(), i+3);
            if(it != mpp[word[i]].end()){
                s.push_back({i, *it});
            }
        }

        sort(s.begin(), s.end(), [](auto &a , auto &b){
            return a.second < b.second;
        });

        // for(auto it:s) cout<<it.first<<","<<it.second<<endl;

        int last_end = -1, cnt = 0;
        for(auto it: s){
            // cout<<it.first << ","<<it.second<<endl;
            if(it.first > last_end){
                cnt++;
                last_end = it.second;
            }
        }

        return cnt;

    }
};