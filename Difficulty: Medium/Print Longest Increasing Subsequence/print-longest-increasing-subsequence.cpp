class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n, 1), backtrack(n, 0);
        iota(backtrack.begin(), backtrack.end(), 0);
        
        int maxInd = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i ; j++){
                if(arr[i] > arr[j]){
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1 + dp[j];
                        backtrack[i] = j;
                    }
                }
                if(dp[i] > dp[maxInd]) maxInd = i;
            }
        }
        vector<int> v;
        int ind = maxInd;
        while(backtrack[ind] != ind){
            v.push_back(arr[ind]);
            ind = backtrack[ind];
        }
        v.push_back(arr[ind]);
        reverse(v.begin(), v.end());
        return v;
    }
};