class Solution {
public:
    void dfs(int n, int m,int row, int col, vector<vector<char>> &board, vector<vector<int>> &visited){
        int direc[4][2]= {{1,0}, {0,1}, {0,-1},{-1,0}};
        visited[row][col] = 1;
        for(int i=0; i<4; i++){
            int newRow = row + direc[i][0];
            int newCol = col + direc[i][1];
            if(newRow >= 0 && newRow<n && newCol >=0 && newCol < m && visited[newRow][newCol] == 0 && board[newRow][newCol] == 'O' ){
                visited[newRow][newCol] = 1;
                dfs(n,m,newRow,newCol,board,visited);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int j=0; j<m; j++){
           if(board[0][j] == 'O' && visited[0][j] == 0){
               dfs(n,m,0,j,board,visited);
           } 
           if(board[n-1][j] == 'O' && visited[n-1][j] == 0){
               dfs(n,m,n-1,j,board,visited);
           } 
        }
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && visited[i][0] == 0){
               dfs(n,m,i,0,board,visited);
           } 
           if(board[i][m-1] == 'O' && visited[i][m-1] == 0){
               dfs(n,m,i,m-1,board,visited);
           }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 1){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};