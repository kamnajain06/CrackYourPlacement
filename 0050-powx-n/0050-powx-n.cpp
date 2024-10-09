class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int absN = abs(n);
        if(x == 1 || n == 0) return 1;
        while(absN > 0){
            if(absN % 2 == 1){
               ans *= x;
            }
            x = x*x;
            absN /= 2;
        }
        return n > 0 ? ans : 1/ans;
    }
};