class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
                cout<<matrix[i][j];
            }
            reverse(matrix[i].begin(), matrix[i].end());
            cout<<endl;
        }
    }
};