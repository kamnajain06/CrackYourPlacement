//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> ans(2);
        int n = arr.size();
        int miss = 1;
        for(int i=0; i<n; i++){
            if(i + 1 < n && arr[i] == arr[i+1]) ans[0] = arr[i];
            if(arr[i] == miss) miss++;
        }
        ans[1] = miss;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends