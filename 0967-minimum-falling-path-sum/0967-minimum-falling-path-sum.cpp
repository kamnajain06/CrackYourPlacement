class Solution {
public:
    bool isValid(int row, int col, int rows, int cols){
        if(row < 0 || col < 0 || row >= rows || col >= cols) return false;
        return true;
    }
    int fun(int row, int col,  vector<vector<int>>& matrix, int rows, int cols, vector<vector<int>> &dp){
        if(!isValid(row, col, rows, cols)) return INT_MAX;
        if(row == rows-1) return matrix[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int op1 = fun(row+1, col, matrix, rows, cols, dp);
        int op2 = fun(row+1, col-1, matrix, rows, cols, dp);
        int op3 = fun(row+1, col+1, matrix, rows, cols, dp);

        return dp[row][col] = matrix[row][col] + min({op1, op2, op3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // vector<vector<int>> dp(rows, vector<int> (cols, -1));
        // int mini = INT_MAX;
        // for(int col = 0; col < cols; col++){
        //     mini = min(mini, fun(0, col, matrix, rows, cols, dp));
        // }
        // return mini;

        // vector<vector<int>> dp(rows, vector<int> (cols, 0));
        // for(int col = 0; col<cols; col++){
        //     dp[0][col] = matrix[0][col];
        // }
        // for(int row = 1; row < rows; row++){
        //     for(int col = 0; col < cols; col++){
        //         int op1 = dp[row-1][col];
        //         int op2 = col-1 >= 0 ? dp[row-1][col-1] : INT_MAX;
        //         int op3 = col+1 < cols ? dp[row-1][col+1] : INT_MAX;
        //         dp[row][col] = matrix[row][col] + min({op1, op2, op3});
        //     }
        // }
        // int mini = INT_MAX;
        // for(int col = 0; col < cols; col++){
        //     mini = min(mini, dp[rows-1][col]);
        // }
        // return mini;

        vector<int> dp(cols, 0);
        for(int col = 0; col<cols; col++){
            dp[col] = matrix[0][col];
        }
        for(int row = 1; row < rows; row++){
            vector<int> temp(cols, 0);
            for(int col = 0; col < cols; col++){
                int op1 = dp[col];
                int op2 = col-1 >= 0 ? dp[col-1] : INT_MAX;
                int op3 = col+1 < cols ? dp[col+1] : INT_MAX;
                temp[col] = matrix[row][col] + min({op1, op2, op3});
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for(int col = 0; col < cols; col++){
            mini = min(mini, dp[col]);
        }
        return mini;
    }
};