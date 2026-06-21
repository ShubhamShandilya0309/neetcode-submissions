class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    void dfs(vector<vector<int>>&vis, vector<vector<char>>& grid,int r, int c){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && vis[nr][nc]==0){
                dfs(vis,grid,nr,nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(vis[r][c]==0){
                dfs(vis,grid,r,c);
                ans+=1;
            }
        }
        return ans;
    }
};