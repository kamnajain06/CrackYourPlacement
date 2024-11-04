class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();
        int cnt = 1;
        for(int i=0; i<word.length(); i++){
            if(i < n-1 && word[i] == word[i+1]){
                cnt++;
                if(cnt == 9){
                    ans += to_string(cnt);
                    ans += word[i];
                    cnt = 1;
                    i++;
                }
            }else{
                ans += to_string(cnt);
                ans += word[i];
                cnt = 1;
            }
        }
        return ans;
    }
};