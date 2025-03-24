class Solution {
public:
    string ans;
    void fun(int ind, string s, int n , int k, string temp, int &cnt){
        if(temp.size() == n){
            cnt += 1;
            if(cnt == k){
                ans = temp;
            }
            return;
        }
        
        for(int i=0; i<3; i++){
            if(ind != i){
                fun(i, s, n, k, temp + s[i], cnt);
            }
        }
    }
    string getHappyString(int n, int k) {
        int cnt = 0;
        fun(-1, "abc", n, k, "", cnt);
        return ans;
    }
};