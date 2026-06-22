class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O' && vis[nr][nc]==0){
                dfs(nr,nc,vis,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
