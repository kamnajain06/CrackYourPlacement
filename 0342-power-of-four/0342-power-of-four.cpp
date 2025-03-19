class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        if((n & (n-1) )== 0){
            int cnt = 0;
            while((n & 1) == 0){
                n = n >> 1;
                cnt++;
            }
            if(cnt & 1) return false;
            else return true;
        }
        return false;
    }
};