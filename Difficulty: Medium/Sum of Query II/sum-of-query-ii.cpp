//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    void buildSegmentTree(int ind , int left, int right, int arr[],  vector<int> &segmentTree){
        if(left == right){
            segmentTree[ind] = arr[left];
            return;
        }
        int mid = (left + right)/2;
        buildSegmentTree(2*ind + 1, left, mid, arr, segmentTree);
        buildSegmentTree(2*ind + 2, mid + 1, right, arr, segmentTree);
        
        segmentTree[ind] = segmentTree[2*ind + 1] + segmentTree[2*ind + 2];
        return;
    }
    int Query(int start, int end, int ind, int left, int right, vector<int> &segmentTree){
        if(end < left || start > right) return 0; //out of bound
        else if(start <= left && right <= end) return segmentTree[ind];
        int mid = (left + right)/2;
        return Query(start, end, 2*ind + 1, left, mid, segmentTree) + Query(start, end, 2*ind + 2, mid+1, right, segmentTree);
    }
    vector<int> querySum(int n,  int arr[], int q, int queries[])
    {
        vector<int> segmentTree(4*n+1, 0);
        vector<int> ans;
        buildSegmentTree(0, 0, n-1, arr, segmentTree);
        for(int i=0; i<2*q; i+=2){
            int temp = Query(queries[i]-1, queries[i+1]-1, 0, 0, n-1, segmentTree);
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends