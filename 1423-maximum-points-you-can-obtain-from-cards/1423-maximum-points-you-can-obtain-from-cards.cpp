class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum = 0;
        int n = cardPoints.size();
        int ans = 0;
        for(auto it:cardPoints){
            totalSum += it;
        }
        int sum = 0;
        for(int i=0; i<n-k; i++){
            sum += cardPoints[i];
        }
        ans = sum;
        int i=0, j=n-k;
        while(j< n && i <= j){
            sum -= cardPoints[i];
            sum += cardPoints[j];
            i++;
            j++;
            ans = min(ans, sum);

        }

        return totalSum-ans;
    }
};