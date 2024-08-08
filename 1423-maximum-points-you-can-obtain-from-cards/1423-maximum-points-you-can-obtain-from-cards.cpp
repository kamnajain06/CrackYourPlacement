class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int totalSum = 0;
        int n = cardPoints.size();
        for(int i=0; i<cardPoints.size(); i++){
            totalSum += cardPoints[i];
        }
        if(k == n) return totalSum;
        for(int i=0; i<n-k; i++){
            sum += cardPoints[i];
        }
        int i=n-k;
        int ans = totalSum - sum;
        while(i< cardPoints.size()){
            sum -= cardPoints[i-n+k];
            sum += cardPoints[i++];
            ans = max(ans,totalSum - sum);
        }
        
        return ans;
    }
};