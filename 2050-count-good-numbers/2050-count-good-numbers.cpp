class Solution {
public:
    int MOD = 1e9 + 7;
    long long calculatePower(long long a , long long b){
        long long res = 1;
        while(b > 0){
            if(b & 1){
                res = ((res%MOD) * (a%MOD))%MOD;
            }
            a = ((a%MOD) * (a%MOD))%MOD;
            b = b >> 1;
        }
        return res % MOD;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long even_num = 1, odd_num = 1;
        if(even) even_num = calculatePower(5, even) % MOD;
        if(odd) odd_num = calculatePower(4, odd) % MOD;

        long long ans = (long long) ((even_num%MOD) * (odd_num%MOD))%MOD;
        return ans%MOD; 
    }
};