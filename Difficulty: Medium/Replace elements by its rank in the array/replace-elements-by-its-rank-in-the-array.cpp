//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int> org;
        vector<int> ans;
        org = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int,int> mpp;
        int cnt = 1;
        for(int i=0; i<N; i++){
            if(mpp.find(arr[i]) == mpp.end()){
                mpp[arr[i]] = cnt;
                cnt++;
            }
        }
        for(auto it:org){
            ans.push_back(mpp[it]);
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends