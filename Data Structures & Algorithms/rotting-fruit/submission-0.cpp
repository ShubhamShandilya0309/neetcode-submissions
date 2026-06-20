class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            int flag = 0;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                        grid[nr][nc]=2;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        flag = 1;
                    }
                }
            }
            if(flag)ans+=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};
