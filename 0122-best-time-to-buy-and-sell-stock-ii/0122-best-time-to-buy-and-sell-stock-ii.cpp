class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int start = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] - start > 0){
                ans += prices[i] - start;
            }
            start = prices[i];
        }
        
        return ans;
    }
};