class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        sort(timePoints.begin(), timePoints.end());
        for(int i=0; i<timePoints.size(); i++){
            string hours = timePoints[i].substr(0,2);
            string min = timePoints[i].substr(3,5);

            int h = stoi(hours);
            int m = stoi(min);
        
            v.push_back(h*60 + m);
        }

        int mini = INT_MAX;


        for(int i=1; i<v.size(); i++){
            int diff = abs(v[i]-v[i-1]) > 720 ? 1440-abs(v[i]-v[i-1]) : abs(v[i]-v[i-1]);
            mini = min(mini, diff );
        }
        int diff = abs(v[v.size()-1]-v[0]) > 720 ? 1440- abs(v[v.size()-1]-v[0]) : abs(v[v.size()-1]-v[0]);
        mini = min(mini, diff);

        return mini;
        
    }
};