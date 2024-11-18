//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // mod = 100000 
        // nodes -> 0,1,2,.....,9999;
        vector<int> dist(100000,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push({0,start});
        dist[start] = 0;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int step = it.first;
            int node = it.second;
            if(node == end) return step;
            for(auto i: arr){
                if(step + 1< dist[(node*i)%100000]){
                    dist[(node*i)%100000] = step+1;
                    q.push({step+1,(node*i)%100000});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends