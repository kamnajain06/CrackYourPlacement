class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> dp(n);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            int twoMul = dp[p2]*2;
            int threeMul = dp[p3]*3;
            int fiveMul = dp[p5]*5;
            
            int mini = min(twoMul, min(threeMul, fiveMul));
            
            dp[i] = mini;
            cout<<dp[i]<<endl;
            if(mini == twoMul) p2++;
            if(mini == threeMul) p3++;
            if(mini == fiveMul) p5++;
            
        }
        
        return dp[n-1];
    }
};