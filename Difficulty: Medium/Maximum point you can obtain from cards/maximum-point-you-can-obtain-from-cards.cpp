//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long sum = 0;
        long long totalSum = 0;
        int n = cardPoints.size();
        for(int i=0; i<cardPoints.size(); i++){
            totalSum += cardPoints[i];
        }
        if(k == n) return totalSum;
        for(int i=0; i<n-k; i++){
            sum += cardPoints[i];
        }
        int i=n-k;
        long long ans = totalSum - sum;
        while(i< cardPoints.size()){
            sum -= cardPoints[i-n+k];
            sum += cardPoints[i++];
            ans = max(ans,totalSum - sum);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends