class Solution {
public:
    bool isPrime(int n){
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    int minSteps(int n) {
        
        if(n==1) return 0;

        if(isPrime(n)) return n;
        
        int ans = 0;

        for(int i=2; i<=sqrt(n); i++){
            while(n%i == 0 && isPrime(i)){
                ans+=i;
                n/=i;
            }
        }
        if(n>1 && isPrime(n)) ans+=n;
        
        return ans;
    }
};