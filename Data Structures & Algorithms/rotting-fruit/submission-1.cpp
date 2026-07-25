class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        int fresh = 0;
        int ans = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int flag = 0;
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        fresh--;
                        flag = 1;
                    }
                }
            }
            if(flag){
                ans+=1;
            }
        }
        return fresh == 0 ? ans : -1;
    }
};