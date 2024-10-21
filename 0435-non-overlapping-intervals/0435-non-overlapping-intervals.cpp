class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        
        // for(auto it: intervals){
        //     cout<<it[0]<<" , "<<it[1]<<endl;
        // }
        for(int i=1; i<intervals.size(); i++){
            // cout<< intervals[i][0] << " < " << end << endl;
            if(intervals[i][0] < end){
                cnt++;
                end = min(end, intervals[i][1] );
            }else{
                end = intervals[i][1];
            }
            // cout<<cnt<<endl;
        }
        return cnt;
    }
};