//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int n, int m,int row, int col, vector<vector<char>> &mat, vector<vector<int>> &visited){
        int direc[4][2]= {{1,0}, {0,1}, {0,-1},{-1,0}};
        visited[row][col] = 1;
        for(int i=0; i<4; i++){
            int newRow = row + direc[i][0];
            int newCol = col + direc[i][1];
            if(newRow >= 0 && newRow<n && newCol >=0 && newCol < m && visited[newRow][newCol] == 0 && mat[newRow][newCol] == 'O' ){
                visited[newRow][newCol] = 1;
                dfs(n,m,newRow,newCol,mat,visited);
            }
        }
        return;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n, vector<char> (m, 'X'));
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int j=0; j<m; j++){
           if(mat[0][j] == 'O' && visited[0][j] == 0){
               dfs(n,m,0,j,mat,visited);
           } 
           if(mat[n-1][j] == 'O' && visited[n-1][j] == 0){
               dfs(n,m,n-1,j,mat,visited);
           } 
        }
        for(int i=0; i<n; i++){
            if(mat[i][0] == 'O' && visited[i][0] == 0){
               dfs(n,m,i,0,mat,visited);
           } 
           if(mat[i][m-1] == 'O' && visited[i][m-1] == 0){
               dfs(n,m,i,m-1,mat,visited);
           }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 1){
                    ans[i][j] = 'O';
                }
            }
        }
        return ans;
    }   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends