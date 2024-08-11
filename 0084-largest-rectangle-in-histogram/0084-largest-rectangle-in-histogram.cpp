class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> s;
        vector<int> nseArr(n,n);
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(!s.empty()) nseArr[i] = s.top().second;
            s.push({heights[i], i});
        }
        return nseArr;
        
    }
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        stack<pair<int,int>> s;
        vector<int> pseArr(n,-1);
        
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top().first>=heights[i]) s.pop();
            if(!s.empty()) pseArr[i] = s.top().second;
            s.push({heights[i], i});
        }
        return pseArr;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nseArr = nse(heights);
        vector<int> pseArr = pse(heights);
        int ans = INT_MIN;
        
        for(int i=0; i<heights.size(); i++){
            ans = max(ans, heights[i]*(nseArr[i]-pseArr[i]-1));
        }
        return ans;
    }
};