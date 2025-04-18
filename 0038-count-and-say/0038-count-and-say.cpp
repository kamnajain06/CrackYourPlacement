class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string temp = countAndSay(n-1);
        int cnt = 1;
        string ans = "";
        for(int i=0; i<temp.length()-1; i++){
            if(temp[i] == temp[i+1]){
                cnt++;
            }else{
                ans += to_string(cnt) + temp[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt) + temp[temp.length()-1];

        return ans;
    }
};