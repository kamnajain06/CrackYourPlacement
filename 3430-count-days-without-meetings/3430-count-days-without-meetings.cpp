class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int cnt = 0;
        int mini = meetings[0][0];
        int maxi = meetings[0][1];
        cnt += mini-1;
        for(int i=1; i<n; i++){
            if(meetings[i][0] <= maxi){
                maxi = max(maxi, meetings[i][1]);
            }else{
                cnt += (meetings[i][0] - maxi - 1);
                mini = meetings[i][0];
                maxi = meetings[i][1];
            }
        }
        cnt += (days - maxi);
        return cnt;
    }
};