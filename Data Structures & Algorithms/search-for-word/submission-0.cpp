class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    bool solve(int idx, int r,int c,vector<vector<char>>& board, string word, vector<vector<int>>& vis){
        vis[r][c]=1;
        if(idx==word.size()-1)return true;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && !vis[nr][nc] && board[nr][nc]==word[idx+1]){
                if(solve(idx+1,nr,nc,board,word,vis)){
                    vis[r][c]=0;
                    return true;
                }
            }
        }
        vis[r][c]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]==word[0]){
                    if(solve(0,i,j,board,word,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};