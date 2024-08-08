class Solution {
public:
    
    int check(vector<vector<int>>& board, int row, int col){
        int directions[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,1}, {-1,-1}, {1,1}, {1,-1}};
        int val = 0;
        for(int i=0; i<8; i++){
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if( (newRow >= 0 && newRow < board.size()) && (newCol >= 0 && newCol < board[0].size())){
                if(board[newRow][newCol] == 1) val++;
            }
        }
        return val;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> nextState(rows, vector<int>(cols, 0));
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                int liveNeighbors = check(board, i, j);
                if(board[i][j] == 0){
                    if(liveNeighbors == 3) nextState[i][j] = 1;
                }else{
                    if(liveNeighbors == 2 || liveNeighbors == 3) nextState[i][j] = 1;
                }
            }
        }
        
        board = nextState;
    }
};