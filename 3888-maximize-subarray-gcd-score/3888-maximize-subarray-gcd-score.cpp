class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int power(int n){
        int cnt = 0;
        while(n % 2 == 0){
            cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxVal = 0;
        for (int i = 0; i < n; i++) {
            long long gcdVal = nums[i];
            long long minPower = 1e9, cnt = 0;
            for (int j = i; j < n; j++) {
                gcdVal = gcd(gcdVal, nums[j]);
                int len = j - i + 1;
                int exp = power(nums[j]);
                // cout << exp << endl;
                if(exp < minPower){
                    cnt = 1;
                    minPower = exp;
                }else if(exp == minPower) cnt++;
                if(cnt <= k){
                    maxVal = max(2*gcdVal*len, maxVal);
                }else{
                    maxVal = max(gcdVal*len, maxVal);
                }
            }
        }
        return maxVal;
    }
};