class Solution {
    bool isSafe(int r, int c,vector<string>& board,int n){
        int ur = r-1, uc = c-1;
        int sc = c-1;
        int lr = r+1, lc = c-1;
        while(ur>=0 && uc>=0){
            if(board[ur][uc]=='Q')return false;
            ur--;
            uc--;
        }
        while(sc>=0){
            if(board[r][sc]=='Q')return false;
            sc--;
        }
        while(lr<n && lc>=0){
            if(board[lr][lc]=='Q')return false;
            lr++;
            lc--;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<string>>& ans, vector<string>& board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,n,ans,board);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,ans,board);
        return ans;
    }
};