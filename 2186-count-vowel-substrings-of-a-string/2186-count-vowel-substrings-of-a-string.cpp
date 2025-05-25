class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        vector<pair<int, int>> v;
        int start = -1, end = -1;
        int i = 0;
        for (; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u') {
                if (start == -1)
                    start =  end = i;
                else
                    end = i;
            } else {
                if (start != -1 && end != -1) {
                    v.push_back({start, end});
                }
                start = -1;
                end = -1;
            }
        }
        if (start != -1) {
            v.push_back({start, end});
        }
        int cnt = 0;
        for(auto it : v){ 
            i = it.first;
            int end = it.second;
            if(end-i+1 < 5) continue;
            unordered_map<char,int> mpp;
            for(int j = i; j<=end; j++){
                mpp[word[j]]++;
                while(mpp.size() >= 5){
                    cnt += end - j+1;
                    mpp[word[i]]--;
                    if(mpp[word[i]] == 0) mpp.erase(word[i]);
                    i++;
                }
            } //O(2m)
        }
        return cnt;
    }
};