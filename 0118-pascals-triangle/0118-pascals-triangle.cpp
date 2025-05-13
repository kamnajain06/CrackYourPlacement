class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int i = 1; i<numRows; i++){
            int j = 1;
            ans[i].push_back(1);
            while(j < i){
                int val = ans[i-1][j]+ ans[i-1][j-1];
                ans[i].push_back(val);
                j++;
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};