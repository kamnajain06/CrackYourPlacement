class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans = 0;
        int sign = 0;
        if(dividend >= 0 && divisor<0 || dividend<0 && divisor>=0) sign = 1;
        long  n = abs(dividend);
        long d = abs(divisor);
        if(dividend == divisor) return 1;
        if(dividend == INT_MAX && divisor == -1) return -INT_MAX;
        while(n >= d){
            int cnt = 0;
            while(n >= (d<<(cnt+1))){
                cnt++;
            }
            ans += 1 << cnt;
            n = n - (d<<cnt);
            
            
        }
        cout<<ans<<endl;
        if(ans == INT_MAX && sign == 0) return INT_MAX;
        else if(ans == INT_MAX && sign == 1) return -INT_MAX;
        // if(ans )
        if(ans == INT_MIN && sign == 0) return INT_MAX;
        else if(ans == INT_MIN && sign == 1) return INT_MIN;
        if(sign){
            return -ans;
        }
        return (int)ans;
    }
};