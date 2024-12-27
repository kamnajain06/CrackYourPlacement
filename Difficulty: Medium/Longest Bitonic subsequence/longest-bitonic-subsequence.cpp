//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> LIS(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev] && LIS[i] < 1+ LIS[prev]) LIS[i] = 1+LIS[prev];
            }
        }
        vector<int> LDS(n, 1);
        for(int i=n-1; i>=0; i--){
            for(int prev = n-1; prev > i; prev--){
                if(nums[i] > nums[prev] && LDS[i] < 1+ LDS[prev]) LDS[i] = 1+LDS[prev];
            }
        }
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(LIS[i] > 1 && LDS[i] > 1) maxLen = max(maxLen, LIS[i]+LDS[i]-1);
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends