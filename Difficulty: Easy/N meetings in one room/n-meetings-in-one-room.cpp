//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> start, vector<int> end) {
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<end.size(); i++){
            pq.push({end[i],start[i]});
        }
        int cnt = 0;
        
        if(!pq.empty()){
            int endTime = pq.top().first;
            pq.pop();
            cnt++;
            while(!pq.empty()){
                if(pq.top().second > endTime){
                    cnt++;
                    endTime = pq.top().first;
                }
                pq.pop();
            }
        }
        return cnt;
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
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends