//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(int w, Item arr[], int n) {
        priority_queue<pair<double,int>> pq;
        for(int i=0 ; i<n; i++){
            pq.push({(double)(arr[i].value)/(arr[i].weight),i});
        }
        double sum = 0;
        while(w >= 0 && !pq.empty()){
            int wt = arr[pq.top().second].weight;
            if(wt <= w){
                sum += arr[pq.top().second].value;
                w -= wt;
            }else{
                sum += (pq.top().first)*(w);
                break;
            }
            pq.pop();
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends