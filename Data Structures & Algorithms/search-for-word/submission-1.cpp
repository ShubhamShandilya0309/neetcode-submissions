class Solution {
    int dc[4]={-1,0,1,0};
    int dr[4]={0,-1,0,1};
    bool solve(int r, int c, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& board, int i, string word){
        if(i == word.size()-1){
            return true;
        }
        vis[r][c] = 1;
        for(int j=0;j<4;j++){
            int nr = r+dr[j];
            int nc = c+dc[j];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]==word[i+1]){
                if(solve(nr,nc,n,m,vis,board,i+1,word)){
                    vis[r][c]=0;
                    return true;
                }
            }
        }
        vis[r][c] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j] == word[0]){
                    if(solve(i,j,n,m,vis,board,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};