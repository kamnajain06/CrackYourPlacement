class Solution {
public:
    
    bool dfs(int i, int j, int k,vector<vector<char>>& board,string word){
        int m = board.size();
        int n = board[0].size();
        
        if(k == word.size()) return true;
        
        int moves[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
        
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='\0'){
            return false;
        }
        
        if(board[i][j] != word[k]) return false;
        
        
        char temp = board[i][j];
        board[i][j] = '\0';
        
        for(int t=0; t<4; t++){
            int new_i = i + moves[t][0];
            int new_j = j + moves[t][1];
            
            if(dfs(new_i,new_j,k+1,board,word)){
                return true;
            }
        }
        
        board[i][j] = temp;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
    return false;
        
    }
};