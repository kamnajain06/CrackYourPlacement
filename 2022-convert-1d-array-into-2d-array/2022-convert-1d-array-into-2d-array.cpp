class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        if(m*n < original.size() || m*n > original.size()) return ans;
        int k = 0;
        for(int i=0; i<m; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                v.push_back(original[k++]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};