class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=1; i<numRows; i++){
            int prevSize = ans[i-1].size();
            int currSize = prevSize + 1;
            vector<int> temp;
            int j = 0;
            for(; j<currSize && j < prevSize; j++){
                if(j == 0){
                    temp.push_back(ans[i-1][j]);
                }else temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            int k = 0;
            while(j < currSize){
                temp.push_back(ans[i-1][k]);
                k++;
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};