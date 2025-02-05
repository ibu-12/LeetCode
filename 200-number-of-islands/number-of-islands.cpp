class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
            
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1' ){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};