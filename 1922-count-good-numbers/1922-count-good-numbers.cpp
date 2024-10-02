class Solution {
public:
    long long modulo = pow(10,9) + 7;
    long long power(long long num, long long times){
        long long ans = 1;
        while(times > 0){
            if(times % 2 == 1){
                ans = (ans*num)%modulo;
            }
            num = (num*num)%modulo;
            times /= 2;
        }
        return ans%modulo;
    }
    int countGoodNumbers(long long n) {
        long long ans = 0;
        if(n%2 == 0){
            long long even = power(5,n/2);
            long long odd = power(4,n/2);
            ans = odd * even;
        }else{
            long long even = power(5,(n+1)/2);
            long long odd = power(4,n/2);
            ans = odd * even;
        }
        
        return ans%modulo;
    }
};