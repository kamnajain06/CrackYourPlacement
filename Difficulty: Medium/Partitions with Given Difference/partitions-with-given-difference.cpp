//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(arr[i] == 0) cnt++;
            else break;
        }
        
        int target = sum;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        if(arr[cnt] <= target){
            dp[arr[cnt]] = 1;
        }
        for(int i=cnt+1; i<n; i++){
            vector<int> temp(target+1, 0);
            temp[0] = 1;
            for(int j=1; j<=target; j++){
                int pick = arr[i] <= j  ? dp[j - arr[i]] : 0;
                int skip = dp[j];
                temp[j] = pick + skip;
            }
            dp = temp;
        }

        int ans = 0;
        for(int target = sum/2; target <= sum; target++){
            if(dp[target]){
                // cout<<dp[target]<<endl;
                if((2*target-sum) == d) ans+=dp[target];
            }
        }
        return (pow(2,cnt))*ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends